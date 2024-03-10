#include QMK_KEYBOARD_H

#define MSTURDY 0
#define QWERTY 1
#define NAV  2
#define SYMB 3
#define NUM  4
#define FUNC 5
#define MOUS 6

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
            KC_V, KC_M, KC_L, KC_C, KC_P,                                    KC_B, MAGIC, KC_U, KC_O, KC_Q,
            HOME_S, HOME_T, HOME_R, HOME_D, KC_Y,                           KC_F, HOME_N, HOME_E, HOME_A, HOME_I,
            KC_X, KC_K, KC_J, KC_G, KC_W,                                KC_Z, KC_H, KC_COMM, KC_DOT, KC_SCLN,
                                           MO(SYMB), MO(MOUS),                                            KC_ESC,
                      MO(NUM), KC_BSPC,KC_DEL,                                                  KC_ENT,KC_SPC,MO(NAV),
                                MO(MOUS),                                                  KC_TAB),
	[QWERTY] = LAYOUT(
            KC_Q, KC_W, KC_E, KC_R, KC_T,                                    KC_Y, KC_U, KC_I, KC_O, KC_P,
            LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,            KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
            KC_Z, KC_X, KC_C, KC_V, KC_B,                                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                                           MO(SYMB), ____,                                            KC_ESC,
                      MO(NUM), KC_BSPC,KC_DEL,                                                  KC_ENT,KC_SPC,MO(NAV),
                                ____,                                                  KC_TAB),
	[NAV] = LAYOUT(
            ____, ____, ____, ____, ____,                                           ____, ____, ____, ____, ____,
            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____,
            ____, ____, ____, ____, ____,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END, ____,
                                        KC_BSPC, KC_DEL,                            ____,
                                    MO(NUM), ____,____,                            ____, ____, KC_TRNS,
                              ____,                                               ____),
	[SYMB] = LAYOUT(KC_GRV, KC_LT, KC_GT, KC_DQUO, KC_QUOT,            KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_PERC,
            KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_HASH,             KC_PIPE, KC_DLR, KC_LPRN, KC_RPRN, KC_QUES,
            KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_AT,              KC_TILD, ____, KC_LCBR, KC_RCBR,KC_EXLM,
                                ____, KC_TRNS,                      KC_ESC,
                            ____,____,____,                 KC_ENT,KC_SPC,____,
                            ____,                               KC_TAB),
	[NUM] = LAYOUT(
            ____, ____, ____, ____, ____,                           ____, KC_7, KC_8, KC_9, ____,
            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,               ____, KC_4, KC_5, KC_6, ____,
            ____, ____, ____, ____, ____,                           KC_0, KC_1, KC_2, KC_3, ____,
                                      KC_TRNS, ____,                KC_ESC,
                                ____, ____,____,                KC_ENT, KC_SPC, MO(NAV),
                                ____,                                   KC_TAB),
	[FUNC] = LAYOUT(
            SET_QWERTY, ____, KC_VOLD, KC_VOLU, KC_MUTE,                          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, SET_MSTURDY,
            LGUI_T(KC_F2), LALT_T(KC_F3), LCTL_T(KC_F4), LSFT_T(KC_F5), KC_F6,              KC_F7, RSFT_T(KC_F8), RCTL_T(KC_F9), LALT_T(KC_F10), RGUI_T(KC_F11),
            KC_F1, ____, ____, ____, ____,                                                  ____, XP(n_tilde,N_tilde), ____, ____, KC_F12,
                                      ____,____,                                            ____,
                                ____, ____,____,                                      ____, ____,____,
                                ____,                                                       ____),
	[MOUS] = LAYOUT(
            KC_MS_BTN3, MOUSE_TRACK_SCROLL, KC_MS_BTN2, KC_MS_BTN1, ____,                                    ____, ____, ____, ____, ____,
            KC_MS_BTN3, MOUSE_TRACK_SCROLL, KC_MS_BTN2, KC_MS_BTN1, ____,    ____, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
               ____, ____, ____, ____, ____,                                ____, ____, ____, ____, ____,
                                    ____, KC_TRNS,                           ____,
                                ____,____,____,                        ____,____,____,
                              KC_TRNS,                                          ____),
};

// Keyboard Logic

#include "features/achordion.h"

void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUS); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool set_scrolling = false;
// Variables to store accumulated scroll values
int64_t scroll_accumulated_h = 0;
int64_t scroll_accumulated_v = 0;
#define TRACK_RESOLUTION  64


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
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
    }
    if (IS_LAYER_ON(NUM) || IS_LAYER_ON(SYMB) || IS_LAYER_ON(NAV) || IS_LAYER_ON(FUNC)) {
        layer_off(MOUS);
    }
    return mouse_report;
}


bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case MOUSE_TRACK_SCROLL:
            return true;
        default:
            return false;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("Layer MSTURDY %b\n", IS_LAYER_ON(MSTURDY));
    dprintf("Layer MOUS %b\n", IS_LAYER_ON(MOUS));
    update_tri_layer(NUM, NAV, FUNC);
    if (!process_achordion(keycode, record)) {return false;}


    if (record->event.pressed) {

//#ifdef REPEAT_KEY_ENABLE
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
//#endif
    }
    switch (keycode) {
        case MOUSE_TRACK_SCROLL: set_scrolling = record->event.pressed; break;
        case SET_MSTURDY: layer_move(MSTURDY); break;
        case SET_QWERTY: layer_move(QWERTY); break;
    }
    return true;
}
void matrix_scan_user(void) {
    achordion_task();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A): // left pinkie
            return TAPPING_TERM + 75;
        case RGUI_T(KC_S): // right pinkie
            return TAPPING_TERM + 75;
        case LALT_T(KC_O):
            return TAPPING_TERM + 35;
        case LALT_T(KC_N):
            return TAPPING_TERM + 35;
        case LCTL_T(KC_E):
            return TAPPING_TERM + 10;
        case RCTL_T(KC_T):
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

//#ifdef REPEAT_KEY_ENABLE
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
//#endif

//#ifdef COMBO_ENABLE
enum combo_events {
  SQUARE_BRACKET,
  PARENTHESIS,
  CURLY_BRACKETS,
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
//#endif /* ifdef COMBO_ENABLE */

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   //debug_matrix=true; */
/*   debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */
