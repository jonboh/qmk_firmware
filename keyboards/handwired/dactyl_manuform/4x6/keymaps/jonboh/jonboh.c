#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_LSFT, KC_QUOT, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL, MO(2), KC_BSPC, KC_SPC, MO(1), KC_LALT, MO(5), MO(6), KC_LEAD, KC_LGUI, KC_DEL, KC_ENT, KC_TAB),
	[1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSLS, KC_LCTL, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PSCR, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_DOWN, KC_UP, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(7), KC_NO, MO(4), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PERC, KC_CIRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_DLR, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM, KC_LSFT, KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, MO(3), KC_NO, MO(7), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD, KC_NO, KC_NO, KC_NO, RGB_M_K, RGB_M_G, KC_TRNS, KC_TRNS, RGB_M_P, RGB_M_B, KC_NO, KC_NO, RGB_TOG, RGB_VAI, KC_NO, KC_NO, BL_TOGG, RGB_VAD),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[5] = LAYOUT(KC_NO, MEH(KC_SCLN), MEH(KC_COMM), MEH(KC_DOT), MEH(KC_P), MEH(KC_Y), MEH(KC_F), MEH(KC_G), MEH(KC_C), MEH(KC_R), MEH(KC_L), MEH(KC_SLSH), KC_NO, MEH(KC_A), MEH(KC_O), MEH(KC_E), MEH(KC_U), MEH(KC_I), MEH(KC_D), MEH(KC_H), MEH(KC_T), MEH(KC_N), MEH(KC_S), MEH(KC_MINS), KC_NO, MEH(KC_QUOT), MEH(KC_Q), MEH(KC_J), MEH(KC_K), MEH(KC_X), MEH(KC_B), MEH(KC_M), MEH(KC_W), MEH(KC_V), MEH(KC_Z), KC_NO, MEH(KC_LBRC), MEH(KC_RBRC), MEH(KC_PLUS), MEH(KC_EQL), KC_NO, KC_NO, MEH(KC_SPC), KC_NO, KC_NO, KC_TRNS, MO(8), KC_NO, KC_NO, KC_NO, MEH(KC_ENT), MEH(KC_TAB)),
	[6] = LAYOUT(KC_NO, HYPR(KC_SCLN), HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_P), HYPR(KC_Y), HYPR(KC_F), HYPR(KC_G), HYPR(KC_C), HYPR(KC_R), HYPR(KC_L), HYPR(KC_SLSH), KC_NO, HYPR(KC_A), HYPR(KC_O), HYPR(KC_E), HYPR(KC_U), HYPR(KC_I), HYPR(KC_D), HYPR(KC_H), HYPR(KC_T), HYPR(KC_N), HYPR(KC_S), HYPR(KC_MINS), KC_NO, HYPR(KC_QUOT), HYPR(KC_Q), HYPR(KC_J), HYPR(KC_K), HYPR(KC_X), HYPR(KC_B), HYPR(KC_M), HYPR(KC_W), HYPR(KC_V), HYPR(KC_Z), KC_NO, HYPR(KC_LBRC), HYPR(KC_RBRC), HYPR(KC_PLUS), HYPR(KC_EQL), KC_NO, HYPR(KC_DEL), KC_NO, KC_NO, KC_NO, MO(8), KC_TRNS, KC_NO, KC_NO, HYPR(KC_DEL), KC_NO, KC_NO),
	[7] = LAYOUT(LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5), LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8), LCTL(KC_F9), LCTL(KC_F10), LCTL(KC_F11), LCTL(KC_F12), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), LSFT(KC_F5), LSFT(KC_F6), LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[8] = LAYOUT(HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), HYPR(KC_F9), HYPR(KC_F10), HYPR(KC_F11), HYPR(KC_F12), LALT(KC_F1), LALT(KC_F2), LALT(KC_F3), LALT(KC_F4), LALT(KC_F5), LALT(KC_F6), LALT(KC_F7), LALT(KC_F8), LALT(KC_F9), LALT(KC_F10), LALT(KC_F11), LALT(KC_F12), MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), MEH(KC_F10), MEH(KC_F11), MEH(KC_F12), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

