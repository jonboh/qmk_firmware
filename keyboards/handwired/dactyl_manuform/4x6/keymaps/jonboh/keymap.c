#define ____ KC_NO

#include "keycodes.h"
#include QMK_KEYBOARD_H

#define MSTURDY 0
#define NAV  1
#define SYMB 2
#define NUM  3
#define FUNC 4

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
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
            ____, KC_V, KC_M, KC_L, KC_C, KC_P,                                    KC_B, MAGIC, KC_U, KC_O, KC_Q,____,
            ____, HOME_S, HOME_T, HOME_R, HOME_D, KC_Y,                       KC_F, HOME_N, HOME_E, HOME_A, HOME_I,____,
            ____, KC_X, KC_K, KC_J, KC_G, KC_W,                                KC_Z, KC_H, KC_COMM, KC_DOT, KC_SCLN,____,
                      ____ , ____ ,                                                   ____ , ____ ,
                                   MO(NUM), MO(SYMB),                      KC_ESC,MO(NAV),
                                  KC_BSPC,KC_DEL,                          ____, KC_SPC,
                                ____, ____,                                KC_ENT,KC_TAB),
	[NAV] = LAYOUT(
	            ____, ____, ____, ____, ____, ____,                                           ____, ____, ____, ____, ____,____,
	            ____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____,____,
	            ____, ____, ____, ____, ____, ____,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END, ____,____,
	                      ____ , ____ ,                                                                       ____ , ____ ,
                                          MO(NUM), ____,                             ____, KC_TRNS,
	                                      KC_BSPC,KC_DEL,                            ____,____,
                                          ____, ____,                                ____,____),
	[SYMB] = LAYOUT(
	            ____, KC_GRV, KC_LT, KC_GT, KC_DQUO, KC_QUOT,            KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_PERC,____,
	            ____, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_HASH,             KC_PIPE, KC_DLR, KC_LPRN, KC_RPRN, KC_QUES,____,
	            ____, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_AT,              KC_TILD, ____, KC_LCBR, KC_RCBR,KC_EXLM,____,
	                      ____ , ____ ,                                                   ____ , ____ ,
	                                        ____, KC_TRNS,                      KC_ESC,____,
	                                        ____,____,                          ____,KC_SPC,
	                                        ____,____,                               KC_ENT,KC_TAB),
	[NUM] = LAYOUT(
	            ____, ____, ____, ____, ____, ____,                           ____, KC_7, KC_8, KC_9, ____,____,
	            ____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,               ____, KC_4, KC_5, KC_6, ____,____,
	            ____, ____, ____, ____, ____, ____,                           KC_0, KC_1, KC_2, KC_3, ____,____,
	                      ____ , ____ ,                                                   ____ , ____ ,
	                                      KC_TRNS, ____,                KC_ESC,MO(NAV),
	                                         ____,____,                ____, KC_SPC,
	                                        ____,____,                 KC_ENT,KC_TAB),
	[FUNC] = LAYOUT(
	            ____, TO(MSTURDY), ____, KC_VOLD, KC_VOLU, KC_MUTE,                          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, TO(MSTURDY),____,
	            ____, LGUI_T(KC_F2), LALT_T(KC_F3), LCTL_T(KC_F4), LSFT_T(KC_F5), KC_F6,              KC_F7, RSFT_T(KC_F8), RCTL_T(KC_F9), LALT_T(KC_F10), KC_F11,____,
	            ____, KC_F1, ____, ____, ____, ____,                                                  ____, XP(n_tilde,N_tilde), ____, ____, KC_F12,____,
	                      ____ , ____ ,                                                   ____ , ____ ,
	                                      ____,____,                                            ____, ____,
	                                ____,____,                                       ____,____,
	                                ____,____,                                                       ____,____),
};

// Keyboard Logic

#include "features/achordion.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(NUM, NAV, FUNC);
    if (!process_achordion(keycode, record)) {return false;}

    if (record->event.pressed) {

        int rep_count = get_repeat_key_count();
        if (rep_count < -1) {
            send_char('n');
            return false;
        }

        switch (keycode) {
            // Macros invoked through the MAGIC key.
            case M_ION:     SEND_STRING(/*i*/"on"); break;
            case M_NION:    SEND_STRING(/*n*/"ion"); break;
            case M_MENT:    SEND_STRING(/*m*/"ent"); break;
            case M_QUEN:    SEND_STRING(/*q*/"uen"); break;
            case M_TMENT:   SEND_STRING(/*t*/"ment"); break;
            case M_THE:     SEND_STRING(/* */"the"); break;
            case M_UPDIR:   SEND_STRING(/*.*/"./"); break;
            case M_EFORE:   SEND_STRING(/*b*/"efore"); break;
            case M_SP_BUT:   SEND_STRING(/*,*/" but"); break;
            case M_HICH:   SEND_STRING(/*w*/"hich"); break;
            case M_UST:   SEND_STRING(/*j*/"ust"); break;
        }
    }  return true;
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


uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            // Behavior for Magic Sturdy's "magic" key.
            case KC_C:
            case KC_P:
            case HOME_D:
            case KC_G: return KC_Y;
            case KC_Y: return KC_P;
            case HOME_R: return KC_L; // R -> L
            case HOME_S: return KC_K; // S -> K
            case KC_K: return KC_S; // K -> S
            case KC_L:  return KC_K;
            case HOME_E: return KC_U;
            case HOME_A: return KC_O; // A -> O
            case KC_O:  return KC_A;// O -> A
            case KC_U:  return KC_E;// U -> E

            case KC_1 ... KC_0: return KC_DOT;
            case KC_SPC: return M_THE; // spc -> THE
            case KC_DOT: return M_UPDIR; // . -> ./
            case KC_COMM: return M_SP_BUT; // . -> ./
            case HOME_I: return M_ION; // I -> ON
            case KC_Q:  return M_QUEN;// Q -> UEN
            case HOME_T: return M_TMENT; // T -> MENT
            case KC_M:  return M_MENT;// M -> ENT
            case HOME_N: return M_NION; // N -> ION
            case KC_W: return M_HICH;
            case KC_J: return M_UST;
            case KC_B: return M_EFORE;
        }
        return KC_NO;
    }
    else if ((mods & MOD_MASK_CTRL)) {
        switch (keycode) {
            case KC_C:  // Ctrl+C -> Ctrl+V
                return C(KC_V);
        }
    }

    return M_THE;
}

// Combos
enum combo_events {
  SQUARE_BRACKET,
  PARENTHESIS,
  CURLY_BRACKETS,
  SCROLL,
};

const uint16_t PROGMEM combo_full_squarebracket[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_full_parenthesis[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM combo_full_curlybracket[] = {KC_LCBR, KC_RCBR, COMBO_END};
combo_t key_combos[] = {
  [SQUARE_BRACKET] = COMBO_ACTION(combo_full_squarebracket),
  [PARENTHESIS] = COMBO_ACTION(combo_full_parenthesis),
  [CURLY_BRACKETS] = COMBO_ACTION(combo_full_curlybracket),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
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
        }
    }
}

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   //debug_matrix=true; */
/*   debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */
