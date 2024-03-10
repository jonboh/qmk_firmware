#include QMK_KEYBOARD_H

#define MSTURDY 0
#define QWERTY 1
#define NAV  2
#define SYMB 3
#define NUM  4
#define FUNC 5
#define MOUSL 6
#define MOUSR 7
#define SYMB_MODL 8
#define SYMB_MODR 9

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
//#ifdef REPEAT_KEY_ENABLE
    M_ION,
    M_NION,
    M_MENT,
    M_QUEN,
    M_TMENT,
    M_THE,
    M_UPDIR,
    M_EFORE,
    M_SP_BUT,
    M_HICH,
    M_UST,
//#endif
    MOUSE_TRACK_SCROLL,
    SET_MSTURDY,
    SET_QWERTY,
};

// Home row mods for Magic Sturdy layer.
#define HOME_S LGUI_T(KC_S)
#define HOME_T LALT_T(KC_T)
#define HOME_R LCTL_T(KC_R)
#define HOME_D LSFT_T(KC_D)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_A RALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)
#define HOME_X LGUI_T(KC_X)
#define HOME_SC RGUI_T(KC_SCLN)
// Alternate Repeat is the "magic" key.
#define MAGIC QK_ALT_REPEAT_KEY

enum unicode_names {
    n_tilde,
    N_tilde
};

const uint32_t unicode_map[] PROGMEM = {
    [n_tilde] = 0x00F1, // ñ
    [N_tilde] = 0x00D1  // Ñ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MSTURDY] = LAYOUT(
            KC_V )
};
