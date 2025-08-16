#include "print.h"
#include <stdint.h>
#include <string.h>
#include "keycodes.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H

#define MSTURDY 0
#define MOUSE 1
#define NAV  2
#define SYMB 3
#define NUM  4
#define FUNC 5

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    MS_TRK_SCRLL,
    SET_MSTURDY,
    M_MAGIC,
};

// Home row mods for Magic Sturdy layer.
#define HOME_R LCTL_T(KC_R)
#define HOME_D LSFT_T(KC_D)
#define HOME_L LGUI_T(KC_L)
#define HOME_C LALT_T(KC_C)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_MAGIC RALT_T(M_MAGIC)
#define HOME_U RGUI_T(KC_U)
#define HOME_MINS RGUI_T(KC_MINS)

#define HOME_1 RSFT_T(KC_1)
#define HOME_2 RCTL_T(KC_2)

#define HOME_6 RSFT_T(KC_6)
#define HOME_7 RCTL_T(KC_7)

#define HOME_F1 RSFT_T(KC_F1)
#define HOME_F2 RCTL_T(KC_F2)

#define HOME_F6 LSFT_T(KC_F6)
#define HOME_F7 LCTL_T(KC_F7)

#define HOME_F11 LALT_T(KC_F11)
#define HOME_F12 RALT_T(KC_F12)
#define HOME_MPLY RALT_T(KC_MPLY)
#define HOME_MSTP RGUI_T(KC_MSTP)
#define HOME_VOLD LGUI_T(KC_VOLD)
#define HOME_VOLU LALT_T(KC_VOLU)

#define MOUSE_V RCTL(RSFT(KC_V))
#define MOUSE_C RCTL(RSFT(KC_C))
#define MT_B_TRK_SCRLL LT(0, KC_B)


enum unicode_names {
    n_tilde,
    N_tilde
};

const uint32_t unicode_map[] PROGMEM = {
    [n_tilde] = 0x00F1, // ñ
    [N_tilde] = 0x00D1  // Ñ
};

#define MS_NORMAL_CPI 650
#define MS_SNIPE_CPI 350

bool set_scrolling = false;
// Variables to store accumulated scroll values
int64_t scroll_accumulated_h = 0;
int64_t scroll_accumulated_v = 0;
#define TRACK_RESOLUTION  64

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return layer_state_set_user(state);
}

void send_mouse_active(void) {
    uint8_t length = 32;
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'M';
    raw_hid_send(response, length);
}

void send_mouse_active_scrolling(void) {
    uint8_t length = 32;
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'S';
    raw_hid_send(response, length);
}

void send_mouse_inactive(void) {
    uint8_t length = 32;
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'K';
    raw_hid_send(response, length);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (IS_LAYER_ON(MOUSE)) {
        if (set_scrolling) {
            send_mouse_active_scrolling();
        } else {
            send_mouse_active();
        }
    } else {
        send_mouse_inactive();
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NAV, NUM, FUNC);
    // use MO(NUM) + MO(SYM) as TO(MOUSE)+Scroll
    if (!IS_LAYER_ON_STATE(state, MOUSE)){
        set_scrolling = false;
        state = update_tri_layer_state(state, SYMB, NUM, MOUSE);
        if (IS_LAYER_ON_STATE(state, MOUSE)) {
            set_scrolling = true;
        }
    }

    if (IS_LAYER_ON_STATE(state, MOUSE)){
        if (set_scrolling){
            send_mouse_active_scrolling();
        } else {
            send_mouse_active();
        }
        pointing_device_set_cpi(MS_SNIPE_CPI);
    } else {
        send_mouse_inactive();
        pointing_device_set_cpi(MS_NORMAL_CPI);
    }

  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MSTURDY] = LAYOUT(
              KC_V, KC_M, HOME_L, HOME_C, KC_P,                           MT_B_TRK_SCRLL, HOME_MAGIC, HOME_U, KC_O, KC_Q,
              KC_S, KC_T, HOME_R, HOME_D, KC_Y,                           KC_F, HOME_N, HOME_E, KC_A, KC_I,
              KC_X, KC_K, KC_J,   KC_G,   KC_W,                           KC_Z, KC_H, KC_COMM, KC_DOT, KC_SCLN,
              ____,          MO(NUM),  KC_MS_BTN1, KC_MS_BTN2,                        KC_ESC, MO(NAV),               MO(MOUSE),
                                  MO(SYMB), KC_BSPC,                              KC_SPC,
                                  KC_TAB,                                         KC_ENT),
    [MOUSE] = LAYOUT(
                ____, ____, KC_RGUI, KC_RALT, ____,                      MS_TRK_SCRLL, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, ____,
                ____, ____, KC_RCTL ,KC_RSFT, ____,                      ____, ____, ____, ____, ____,
                ____, ____, ____, ____, ____,                                ____, ____, ____, ____, ____,
                ____,         MO(NUM), KC_MS_BTN1, KC_MS_BTN2,                                            TO(MSTURDY),____, KC_TRNS,
                              MO(SYMB), KC_BSPC,                                                   KC_SPC,
                              KC_TAB,                                                           KC_ENT),
    [NAV] = LAYOUT(
                ____, ____, KC_LGUI, KC_LALT, ____,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END, ____,
                ____, ____, KC_LCTL, KC_LSFT, ____,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  ____,
                ____, ____,    ____,    ____, ____,                     ____,    ____,    ____,  ____,     ____,
                ____,                MO(NUM),____, ____,                    KC_ESC,KC_TRNS, ____,
                          ____, KC_BSPC,                                       KC_SPC,
                          KC_TAB,                                              KC_ENT),
    [SYMB] = LAYOUT(
                KC_CIRC,KC_LBRC, KC_RBRC, KC_DQUO, KC_AT,               KC_TILD, M_MAGIC, KC_PERC, KC_AMPR, CW_TOGG,
                KC_GRV, KC_LPRN, KC_RPRN, KC_PIPE, KC_UNDS,             KC_DLR, KC_COLN, KC_SLSH, KC_BSLS, ____,
                ____,   KC_LCBR, KC_RCBR, KC_QUOT, KC_HASH,            KC_ASTR, KC_EQL, KC_QUES, KC_EXLM, ____,
                ____,            MO(NUM),    ____, ____,                   KC_ESC, ____,                    ____,
                                  KC_TRNS, KC_BSPC,                              KC_SPC,
                                  KC_TAB,                                        KC_ENT),
    [NUM] = LAYOUT(
                ____, ____, KC_LGUI, KC_LALT, ____,             MS_TRK_SCRLL, HOME_MAGIC, HOME_MINS, KC_PLUS, KC_PERC,
                KC_9, KC_8, HOME_7, HOME_6, KC_5,                     KC_0, HOME_1, HOME_2, KC_3, KC_4,
                ____, ____,  ____, ____, ____,                        KC_ASTR, KC_EQL, KC_COMM, KC_DOT, KC_SCLN,
                ____,             KC_TRNS, KC_MS_BTN3, ____,                       KC_ESC,MO(NAV),       ____,
                                  MO(SYMB), KC_BSPC,                           KC_SPC,
                                  KC_TAB,                                      KC_ENT),
    [FUNC] = LAYOUT(
                ____, ____, HOME_VOLD, HOME_VOLU, KC_MUTE,         KC_MPRV, HOME_MPLY, HOME_MSTP, KC_MNXT, ____,
                KC_F9, KC_F8, HOME_F7, HOME_F6, KC_F5,             KC_F10, HOME_F1, HOME_F2, KC_F3, KC_F4,
                ____, ____, ____, KC_F11,____,                     ____, KC_F12, UP(n_tilde,N_tilde), ____, ____,
                ____,             KC_TRNS,____,____,                    KC_ESC, KC_TRNS,                         ____,
                                  ____, KC_BSPC,                           KC_SPC,
                                  KC_TAB,                                  KC_ENT)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
LAYOUT(
                'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
                'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
                'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
                'L',           'L', 'L','L', 'R','R',            'R',
                               'L', 'L',         'R',
                                    'L',         'R');


// Effects based on previously typed keys: https://getreuer.info/posts/keyboards/triggers/index.html#based-on-previously-typed-keys
#define RECENT_KEYS_TIMEOUT_MS 2000  // Timeout in milliseconds.
#define RECENT_SIZE 8    // Number of keys in `recent` buffer.

static uint16_t recent[RECENT_SIZE] = {KC_NO};
static uint16_t deadline = 0;

static void clear_recent_keys(void) {
  memset(recent, 0, sizeof(recent));  // Set all zeros (KC_NO).
}

// Handles one event. Returns true if the key was appended to `recent`.
static bool update_recent_keys(uint16_t keycode, keyrecord_t* record) {
  if (!record->event.pressed) { return false; }

  if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
    clear_recent_keys();  // Avoid interfering with hotkeys.
    return false;
  }

  // Handle tap-hold keys.
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return false; }
      keycode &= 0xff;  // Get tapping keycode.
  }

  switch (keycode) {
    case KC_A ... KC_SLASH:  // These keys type letters, digits, symbols.
    case KC_AT:
    case KC_DQUO:
      break;

    case KC_LSFT:  // These keys don't type anything on their own.
    case KC_RSFT:
    case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
      return false;

    default:  // Avoid acting otherwise, particularly on navigation keys.
      clear_recent_keys();
      return false;
  }

  // Slide the buffer left by one element.
  memmove(recent, recent + 1, (RECENT_SIZE - 1) * sizeof(*recent));

  recent[RECENT_SIZE - 1] = keycode;
  deadline = record->event.time + RECENT_KEYS_TIMEOUT_MS;
  return true;
}

void housekeeping_task_user(void) {
  if (recent[RECENT_SIZE - 1] && timer_expired(timer_read(), deadline)) {
    clear_recent_keys();  // Timed out; clear the buffer.
  }
}



/* void pointing_device_init_user(void) { */
/*     set_auto_mouse_layer(MOUS); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer> */
/*     set_auto_mouse_enable(true);         // always required before the auto mouse feature will work */
/* } */



report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // if (!IS_LAYER_ON(MOUSE) && !IS_LAYER_ON(NUM)){
    //     set_scrolling = false;
    // }
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += mouse_report.x * TRACK_RESOLUTION / TRACK_DIVISOR;
        scroll_accumulated_v += -mouse_report.y * TRACK_RESOLUTION / TRACK_DIVISOR;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = scroll_accumulated_h / TRACK_RESOLUTION;
        mouse_report.v = scroll_accumulated_v / TRACK_RESOLUTION;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= mouse_report.h * TRACK_RESOLUTION;
        scroll_accumulated_v -= mouse_report.v * TRACK_RESOLUTION;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        // mouse_report.x = 1.15*mouse_report.x - 0.57*mouse_report.y;
        // mouse_report.y = 2*mouse_report.y - 1.73*mouse_report.x;
        // int64_t x = mouse_report.x;
        // int64_t y = mouse_report.y;
        // mouse_report.x = 3*(x + 0.3*y);
        // mouse_report.y = 1.5*y;
        // mouse_report.x = 1.5 * mouse_report.x;

    }
    return mouse_report;
}


void handle_magic_key(void) {
    switch (recent[RECENT_SIZE - 1]) {
        case KC_C:
        case KC_P:
        case KC_D:
        case KC_G: SEND_STRING("y"); break;
        case KC_Y: SEND_STRING("p"); break;
        case KC_R: SEND_STRING("l"); break;
        case KC_S: SEND_STRING("k"); break;
        case KC_K: SEND_STRING("s"); break;
        case KC_L: SEND_STRING("k"); break;
        case KC_E: SEND_STRING("u"); break;
        case KC_A: SEND_STRING("o"); break;
        case KC_O: SEND_STRING("a"); break;
        case KC_U: SEND_STRING("e"); break;
        case KC_I: SEND_STRING("on"); break;
        case KC_N: SEND_STRING("ion"); break;
        case KC_Q: SEND_STRING("uen"); break;
        case KC_M: SEND_STRING("ent"); break;
        case KC_T: SEND_STRING("ment"); break;
        case KC_B: SEND_STRING("efore"); break;
        case KC_W: SEND_STRING("hich"); break;
        case KC_J: SEND_STRING("ust"); break;
        case KC_SPC: SEND_STRING("the"); break;
        case KC_DOT: SEND_STRING("./"); break;
        case KC_COMM: SEND_STRING(" but"); break;
        case KC_QUOT: SEND_STRING("'"); tap_code16(KC_LEFT); break;
        case KC_DQUO: tap_code16(KC_DQUO); tap_code16(KC_LEFT); break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    // Prior to recent key update to not match against
    switch (keycode) {
        case HOME_MAGIC:
            if (record->tap.count && record->event.pressed ) {
                // from: https://www.reddit.com/r/olkb/comments/yodezj/qmk_macro_on_tap_modifier_on_hold/
                // we implement the tap logic manually as ther HOME_MAGIC is not a basic  keycode
                handle_magic_key();
                return false;
            }
            break;
    }

    if (update_recent_keys(keycode, record)) {
      // Other recent based commands
      // Expand "@me" to my email address.
      if (recent[RECENT_SIZE - 3] == KC_AT &&
          recent[RECENT_SIZE - 2] == KC_M &&
          recent[RECENT_SIZE - 1] == KC_E) {
        SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) "jon.bosque.hernando@gmail.com");
        return false;
      }
      // Expand "@job" to my job email address.
      if (recent[RECENT_SIZE - 4] == KC_AT &&
          recent[RECENT_SIZE - 3] == KC_J &&
          recent[RECENT_SIZE - 2] == KC_O &&
          recent[RECENT_SIZE - 1] == KC_B
          ) {
        SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) "jon.bosque@optimitive.com");
        return false;
      }
    }

    // Shift+Backspace= Delete, see https://getreuer.info/posts/keyboards/macros3/index.html#shift-backspace-delete
    switch (keycode) {
        case KC_BSPC: {
          static uint16_t registered_key = KC_NO;
          if (record->event.pressed) {  // On key press.
            const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
            uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
            uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
            if (shift_mods) {  // At least one shift key is held.
              registered_key = KC_DEL;
              // If one shift is held, clear it from the mods. But if both
              // shifts are held, leave as is to send Shift + Del.
              if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
                del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
                unregister_mods(MOD_MASK_SHIFT);
              }
            } else {
              registered_key = KC_BSPC;
            }

            register_code(registered_key);
            set_mods(mods);
          } else {  // On key release.
            unregister_code(registered_key);
          }
        } return false;
    }
    switch (keycode) {
        static bool ms_b2_pressed;
        case KC_MS_BTN2:
            ms_b2_pressed = record->event.pressed;
            return true;
        case MOUSE_C:
            static uint16_t mouse_c_ms_timer;
            if (!ms_b2_pressed) {
                if (record->event.pressed) {
                    // When keycode MOUSE_C is pressed
                    mouse_c_ms_timer = timer_read();
                    register_mods(MOD_LALT);
                } else {
                    // When keycode MOUSE_C is released
                    if (timer_elapsed(mouse_c_ms_timer) < TAPPING_TERM) {
                        // This was a tap, unregister alt and handle normally
                        unregister_mods(MOD_LALT);
                        return true; // handle normally
                    } else {
                        // This was a hold, simply unregister shift
                        unregister_mods(MOD_LALT);
                    }
                }
                return false;
            } else {
                layer_move(MSTURDY);
                tap_code16(RCTL(KC_C));
                return false;
            }
        case MT_B_TRK_SCRLL:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_B); // Intercept tap function to send KC_B
            } else if (record->event.pressed) {
                set_scrolling = record->event.pressed;
                if (set_scrolling) {
                    send_mouse_active_scrolling();
                } else {
                    if (IS_LAYER_ON(MOUSE)){
                        send_mouse_active();
                    } else {
                        send_mouse_inactive();
                    }
                }
            } else {
                set_scrolling = false;
                send_mouse_inactive();
            }
            return false;
        case MS_TRK_SCRLL:
            set_scrolling = record->event.pressed;
            if (set_scrolling) {
                send_mouse_active_scrolling();
            } else {
                if (IS_LAYER_ON(MOUSE)){
                    send_mouse_active();
                } else {
                    send_mouse_inactive();
                }
            }
            return false;
            break;
        case SET_MSTURDY: layer_move(MSTURDY); break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_B_TRK_SCRLL:
        case HOME_L:
        case HOME_C:
        case HOME_U:
        case HOME_MAGIC:
        case HOME_MINS:
            return TAPPING_TERM + 20;
        case HOME_R:
        case HOME_E:
        case HOME_2:
        case HOME_F2:
        case HOME_7:
        case HOME_F7:
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
}

//#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        del_weak_mods(MOD_BIT(KC_LSFT));  // delete shift to next key.
    } else {
        // Do something when Caps Word deactivates.
    }
}
//#endif


//#ifdef COMBO_ENABLE
enum combo_events {
  SQUARE_BRACKET,
  PARENTHESIS,
  CURLY_BRACKETS,
  AMPERSAND,
  LESSTHAN_GREATERTHAN,
};

const uint16_t PROGMEM combo_full_squarebracket[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_full_parenthesis[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM combo_full_curlybracket[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM combo_full_ampersand[] = {KC_RPRN, KC_PIPE, COMBO_END};
const uint16_t PROGMEM combo_full_lessthangreaterthan[] = {KC_LT, KC_GT, COMBO_END};
combo_t key_combos[] = {
  [SQUARE_BRACKET] = COMBO_ACTION(combo_full_squarebracket),
  [PARENTHESIS] = COMBO_ACTION(combo_full_parenthesis),
  [CURLY_BRACKETS] = COMBO_ACTION(combo_full_curlybracket),
  [AMPERSAND] = COMBO_ACTION(combo_full_ampersand),
  [LESSTHAN_GREATERTHAN] = COMBO_ACTION(combo_full_lessthangreaterthan),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    print("processing combo");
    if (pressed) {
        switch(combo_index) {
            case SQUARE_BRACKET:
                send_string("[]");
                tap_code16(KC_LEFT);
                break;
            case PARENTHESIS:
                send_string("()");
                tap_code16(KC_LEFT);
                break;
            case CURLY_BRACKETS:
                send_string("{}");
                tap_code16(KC_LEFT);
                break;
            case AMPERSAND:
                send_string("&");
                break;
            case LESSTHAN_GREATERTHAN:
                send_string("<>");
                tap_code16(KC_LEFT);
                break;
        }
    }
}
//#endif /* ifdef COMBO_ENABLE */

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
#endif
