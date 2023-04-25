#include "keycode.h"
#include QMK_KEYBOARD_H

#define BASE 0
#define NAV  1
#define SYMB 2
#define NUM  3
#define FUNC 4
#define MEDI 5
#define MOUS 6


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
            KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,                                    KC_F, KC_G, KC_C, KC_R, KC_L,
            LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I,            KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),
            LT(MEDI, KC_DEL), KC_Q, KC_J, KC_K, KC_X,                                KC_B, KC_M, KC_W, KC_V, KC_Z,
                                           MO(SYMB), ____,                                           KC_SPC, MO(NAV),
                                  MO(NUM), KC_BSPC,KC_ESC,                                                  KC_TAB,
                                MO(MOUS),                                                 KC_ENT, ____),
	[NAV] = LAYOUT(
            ____, ____, ____, ____, ____,                                           ____, ____, ____, ____, ____,
            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____,
            ____, ____, ____, ____, ____,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END, ____,
                                        ____,____,                                             ____, KC_TRNS,
                                MO(NUM), KC_BSPC,KC_ESC,                                            ____,
                              ____,                                             ____, ____),
	[SYMB] = LAYOUT(KC_GRV, KC_LT, KC_GT, KC_DQUO, KC_QUOT,            KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_PERC,
            KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_HASH,             KC_PIPE, KC_DLR, KC_LPRN, KC_RPRN, KC_QUES,
            KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_AT,              KC_TILD, ____, KC_LCBR, KC_RCBR,KC_EXLM,
                                ____, KC_TRNS,                                   KC_SPC, ____,
                            ____,____,____,                                      KC_TAB,
                            ____,                                   KC_ENT, ____),
	[NUM] = LAYOUT(
            ____, ____, ____, ____, ____,                           ____, KC_7, KC_8, KC_9, ____,
            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,               ____, KC_4, KC_5, KC_6, ____,
            ____, ____, ____, ____, ____,                           KC_0, KC_1, KC_2, KC_3, ____,
                                      KC_TRNS, ____,                                   KC_SPC, MO(NAV),
                                ____, ____,____,                                           KC_TAB,
                                ____,                                   KC_ENT, ____),
	[FUNC] = LAYOUT(
            ____, ____, ____, ____, ____,                                                   ____, ____, ____, ____, ____,
            LGUI_T(KC_F2), LALT_T(KC_F3), LCTL_T(KC_F4), LSFT_T(KC_F5), KC_F6,              KC_F7, RSFT_T(KC_F8), RCTL_T(KC_F9), LALT_T(KC_F10), KC_F11,
            KC_F1, ____, ____, ____, ____,                                                  ____, ____, ____, ____, KC_F12,
                                      ____,____,                                                       ____,____,
                                ____, ____,____,                                                        ____,
                                ____,                                                       ____, ____),
	[MEDI] = LAYOUT(
            ____, ____, ____, ____, ____,                                   ____, ____, ____, ____, ____,
            ____, ____, KC_VOLD, KC_VOLU, KC_MUTE,                          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, ____,
            KC_TRNS, DT_DOWN, DT_UP, ____, ____,                               ____, ____, ____, ____, ____,
                                     ____,____,                                     ____,____,
                                ____,____,____,                                          ____,
                                ____,                                    ____, ____),
	[MOUS] = LAYOUT(
            ____, ____, ____, ____, ____,                                    ____, ____, ____, ____, ____,
           KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,                        ____, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, ____,
            ____, ____, ____, ____, ____,                                   KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, ____,
                                     ____, ____,                                      ____, ____,
                                ____,____,____,                                             ____,
                              KC_TRNS,                                          ____, ____),
};

// Keyboard Logic

#include "features/achordion.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(NUM, NAV, FUNC);
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
