#include QMK_KEYBOARD_H

#define _BASE 0
#define _ARROW_NUM 1
#define _SYMBOLS 2
#define _FN 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
            KC_ESC, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,                   KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
            KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I,                          KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, 
            KC_LSFT, KC_QUOT, KC_Q, KC_J, KC_K, KC_X,                        KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, 
            KC_LBRC, KC_RBRC,                                               KC_PLUS, KC_EQL,
            MO(2), KC_SPC,                                              KC_ENT, MO(1), 
                            KC_BSPC, KC_DEL,                            KC_END, KC_HOME,
                            KC_GRV, KC_LALT,                            KC_LGUI, KC_TAB),
	[_ARROW_NUM] = LAYOUT(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSLS,
            KC_LCTL, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO,                        KC_PSCR, KC_4, KC_5, KC_6, KC_NO, KC_NO,
                KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO,
                KC_NO, KC_NO,                                               KC_NO, KC_NO, 
                    KC_NO, KC_NO,                                            KC_NO, KC_NO, 
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT),
	[_SYMBOLS] = LAYOUT(
            KC_NO, KC_CIRC, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
            KC_LCTL, KC_DLR, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,                    KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM, 
            KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, 
            KC_NO, KC_NO,                                                            KC_NO, KC_NO,
            KC_NO, MO(3),                                                                KC_NO, KC_NO,
            KC_NO, KC_NO,                                                               KC_NO, KC_NO,
            KC_NO, KC_NO,                                                                   KC_NO, KC_NO), 
	[_FN] = LAYOUT(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                               KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
            KC_NO, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, KC_NO,                        KC_NO, KC_MPLY, KC_MSTP, KC_MUTE, KC_NO, KC_NO, 
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD, KC_NO, 
                        KC_NO, KC_NO,                                                           KC_NO, KC_NO,
                        KC_NO, KC_NO,                                                           RGB_M_P, RGB_M_B,
                        KC_NO, KC_NO,                                                            RGB_TOG, RGB_VAI,
                        KC_NO, KC_NO,                                                            KC_NO, RGB_VAD)
};

