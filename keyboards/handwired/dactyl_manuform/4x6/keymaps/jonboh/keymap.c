#include "jonboh.c"

#define _BASE 0
#define _ARROW_NUM 1
#define _SYMBOLS 2
#define _FN 3

#include "oled_setup.h"
#include "features/achordion.h"

//layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _UPPER, _ADJUST); }

// Replaces a mod-tap key's hold function with its one-shot counterpart.
static bool oneshot_mod_tap(uint16_t keycode, keyrecord_t* record) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      const uint8_t mods = (keycode >> 8) & 0x1f;
      add_oneshot_mods(((mods & 0x10) == 0) ? mods : (mods << 4));
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {return false;}
   switch (keycode) {
    case LSFT_T(KC_U):
    case RSFT_T(KC_H):
      return oneshot_mod_tap(keycode, record);
  }
   // Luna handling
   switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
#ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
#endif
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
#endif
            break;
    }
    return true;
}
void matrix_scan_user(void) {
    achordion_task();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A): // left pinkie
            return TAPPING_TERM + 50;
        case RGUI_T(KC_S): // right pinkie
            return TAPPING_TERM + 50;
        case LALT_T(KC_O):
            return TAPPING_TERM + 25;
        case LALT_T(KC_N):
            return TAPPING_TERM + 25;
        case LCTL_T(KC_E):
            return TAPPING_TERM + 10;
        case RCTL_T(KC_T):
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
}
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
    } else {
        // Do something when Caps Word deactivates.
    }
}
