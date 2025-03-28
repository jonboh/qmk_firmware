// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file achordion.c
 * @brief Achordion implementation
 *
 * For full documentation, see
 * <https://getreuer.info/posts/keyboards/achordion>
 */

#include "achordion.h"

// Copy of the `record` and `keycode` args for the current active tap-hold key.
static keyrecord_t tap_hold_record;
static uint16_t tap_hold_keycode = KC_NO;
// Timeout timer. When it expires, the key is considered held.
static uint16_t hold_timer = 0;
// Eagerly applied mods, if any.
static uint8_t eager_mods = 0;

// Achordion's current state.
enum {
  // A tap-hold key is pressed, but hasn't yet been settled as tapped or held.
  STATE_UNSETTLED,
  // Achordion is inactive.
  STATE_RELEASED,
  // Active tap-hold key has been settled as tapped.
  STATE_TAPPING,
  // Active tap-hold key has been settled as held.
  STATE_HOLDING,
  // This state is set while calling `process_record()`, which will recursively
  // call `process_achordion()`. This state is checked so that we don't process
  // events generated by Achordion and potentially create an infinite loop.
  STATE_RECURSING,
};
static uint8_t achordion_state = STATE_RELEASED;

// Calls `process_record()` with state set to RECURSING.
static void recursively_process_record(keyrecord_t* record, uint8_t state) {
  achordion_state = STATE_RECURSING;
  process_record(record);
  achordion_state = state;
}

// Clears eagerly-applied mods.
static void clear_eager_mods(void) {
  unregister_mods(eager_mods);
  eager_mods = 0;
}

// Sends hold press event and settles the active tap-hold key as held.
static void settle_as_hold(void) {
  clear_eager_mods();
  // Create hold press event.
  recursively_process_record(&tap_hold_record, STATE_HOLDING);
}

bool process_achordion(uint16_t keycode, keyrecord_t* record) {
  // Don't process events that Achordion generated.
  if (achordion_state == STATE_RECURSING) {
    return true;
  }

  // Determine whether the current event is for a mod-tap or layer-tap key.
  const bool is_mt = QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX;
  const bool is_tap_hold =
      is_mt || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX);
  // Check key position to avoid acting on combos.
  const bool is_physical_pos =
      (record->event.key.row < 254 && record->event.key.col < 254);

  if (achordion_state == STATE_RELEASED) {
    if (is_tap_hold && record->tap.count == 0 && record->event.pressed &&
        is_physical_pos) {
      // A tap-hold key is pressed and considered by QMK as "held".
      const uint16_t timeout = achordion_timeout(keycode);
      if (timeout > 0) {
        achordion_state = STATE_UNSETTLED;
        // Save info about this key.
        tap_hold_keycode = keycode;
        tap_hold_record = *record;
        hold_timer = record->event.time + timeout;

        if (is_mt) {  // Apply mods immediately if they are "eager."
          uint8_t mod = (tap_hold_keycode >> 8) & 0x1f;
          if (achordion_eager_mod(mod)) {
            eager_mods = ((mod & 0x10) == 0) ? mod : (mod << 4);
            register_mods(eager_mods);
          }
        }

        dprintf("Achordion: Key 0x%04X pressed.%s\n", keycode,
                eager_mods ? " Set eager mods." : "");
        return false;  // Skip default handling.
      }
    }

    return true;  // Otherwise, continue with default handling.
  }

  if (keycode == tap_hold_keycode && !record->event.pressed) {
    // The active tap-hold key is being released.
    if (achordion_state == STATE_HOLDING) {
      dprintln("Achordion: Key released. Plumbing hold release.");
      tap_hold_record.event.pressed = false;
      // Plumb hold release event.
      recursively_process_record(&tap_hold_record, STATE_RELEASED);
    } else {
      dprintf("Achordion: Key released.%s\n",
              eager_mods ? " Clearing eager mods." : "");
      if (is_mt) {
        clear_eager_mods();
      }
    }

    achordion_state = STATE_RELEASED;
    return false;
  }

  if (achordion_state == STATE_UNSETTLED && record->event.pressed) {
    // Press event occurred on a key other than the active tap-hold key.

    // If the other key is *also* a tap-hold key and considered by QMK to be
    // held, then we settle the active key as held. This way, things like
    // chording multiple home row modifiers will work, but let's our logic
    // consider simply a single tap-hold key as "active" at a time.
    //
    // Otherwise, we call `achordion_chord()` to determine whether to settle the
    // tap-hold key as tapped vs. held. We implement the tap or hold by plumbing
    // events back into the handling pipeline so that QMK features and other
    // user code can see them. This is done by calling `process_record()`, which
    // in turn calls most handlers including `process_record_user()`.
    if (!is_physical_pos || (is_tap_hold && record->tap.count == 0) ||
        achordion_chord(tap_hold_keycode, &tap_hold_record, keycode, record)) {
      dprintln("Achordion: Plumbing hold press.");
      settle_as_hold();
    } else {
      clear_eager_mods();  // Clear in case eager mods were set.

      dprintln("Achordion: Plumbing tap press.");
      tap_hold_record.tap.count = 1;  // Revise event as a tap.
      tap_hold_record.tap.interrupted = true;
      // Plumb tap press event.
      recursively_process_record(&tap_hold_record, STATE_TAPPING);

#if TAP_CODE_DELAY > 0
      wait_ms(TAP_CODE_DELAY);
#endif  // TAP_CODE_DELAY > 0

      dprintln("Achordion: Plumbing tap release.");
      tap_hold_record.event.pressed = false;
      // Plumb tap release event.
      recursively_process_record(&tap_hold_record, STATE_TAPPING);
    }

    recursively_process_record(record, achordion_state);  // Re-process event.
    return false;  // Block the original event.
  }

  return true;
}

void achordion_task(void) {
  if (achordion_state == STATE_UNSETTLED &&
      timer_expired(timer_read(), hold_timer)) {
    dprintln("Achordion: Timeout. Plumbing hold press.");
    settle_as_hold();  // Timeout expired, settle the key as held.
  }
}

// Returns true if `pos` on the left hand of the keyboard, false if right.
static bool on_left_hand(keypos_t pos) {
#ifdef SPLIT_KEYBOARD
  return pos.row < MATRIX_ROWS / 2;
#else
  return (MATRIX_COLS > MATRIX_ROWS) ? pos.col < MATRIX_COLS / 2
                                     : pos.row < MATRIX_ROWS / 2;
#endif
}

bool achordion_opposite_hands(const keyrecord_t* tap_hold_record,
                              const keyrecord_t* other_record) {
  return on_left_hand(tap_hold_record->event.key) !=
         on_left_hand(other_record->event.key);
}

// By default, use the BILATERAL_COMBINATIONS rule to consider the tap-hold key
// "held" only when it and the other key are on opposite hands.
__attribute__((weak)) bool achordion_chord(uint16_t tap_hold_keycode,
                                           keyrecord_t* tap_hold_record,
                                           uint16_t other_keycode,
                                           keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}

// By default, the timeout is 1000 ms for all keys.
__attribute__((weak)) uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 250;
}

// By default, hold Shift and Ctrl mods eagerly.
__attribute__((weak)) bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;

    default:
      return false;
  }
}
