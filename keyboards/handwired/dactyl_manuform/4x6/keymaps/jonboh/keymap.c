#include "jonboh.c"

#define _BASE 0
#define _ARROW_NUM 1
#define _SYMBOLS 2
#define _FN 3

#include "features/achordion.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(3, 1, 4);
    if (!process_achordion(keycode, record)) {return false;}
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

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   //debug_matrix=true; */
/*   debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */
