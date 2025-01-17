// #include "../keymap_support.c"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>
// #include "svalboard.h"
#include "../features/achordion.h"

enum custom_keycodes {
    M_ION = SAFE_RANGE,
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
    M_QUOT,
    M_DQUO,
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

#define LAYER_COLOR(name, color) rgblight_segment_t const (name)[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, color})

LAYER_COLOR(layer0_colors, HSV_GREEN); // NORMAL
LAYER_COLOR(layer1_colors, HSV_GREEN); // NORMAL_HOLD
LAYER_COLOR(layer2_colors, HSV_ORANGE); // FUNC
LAYER_COLOR(layer3_colors, HSV_ORANGE); // FUNC_HOLD
LAYER_COLOR(layer4_colors, HSV_AZURE); // NAS
LAYER_COLOR(layer5_colors, HSV_AZURE); // would be NAS hold
LAYER_COLOR(layer6_colors, HSV_RED); // maybe 10kp
LAYER_COLOR(layer7_colors, HSV_RED);
LAYER_COLOR(layer8_colors, HSV_PINK);
LAYER_COLOR(layer9_colors, HSV_PURPLE);
LAYER_COLOR(layer10_colors, HSV_CORAL);
LAYER_COLOR(layer11_colors, HSV_SPRINGGREEN);
LAYER_COLOR(layer12_colors, HSV_TEAL);
LAYER_COLOR(layer13_colors, HSV_TURQUOISE);
LAYER_COLOR(layer14_colors, HSV_YELLOW);
LAYER_COLOR(layer15_colors, HSV_MAGENTA); // MBO
#undef LAYER_COLOR

const rgblight_segment_t*  const __attribute((weak))sval_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer0_colors, layer1_colors, layer2_colors, layer3_colors,
    layer4_colors, layer5_colors, layer6_colors, layer7_colors,
    layer8_colors, layer9_colors, layer10_colors, layer11_colors,
    layer12_colors, layer13_colors, layer14_colors, layer15_colors
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  for (int i = 0; i < RGBLIGHT_LAYERS; ++i) {
      rgblight_set_layer_state(i, layer_state_cmp(state, i));
  }
  return state;
}



void keyboard_post_init_user(void) {
  // Customise these values if you need to debug the matrix
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  rgblight_layers = sval_rgb_layers;
}

enum layer {
    NORMAL,
    NAV,
    NUM,
    SYMB,
    MOUSE
    // NORMAL_HOLD,
    // FUNC,
    // FUNC_HOLD,
    // NAS,
    // MBO = MH_AUTO_BUTTONS_LAYER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ HOME_N,     MAGIC,          XXXXXXX,        KC_H,           KC_F, XXXXXXX,
        /*R2*/ HOME_E,     KC_U,           XXXXXXX,        KC_COMMA,       KC_B, XXXXXXX,
        /*R3*/ HOME_A,     KC_O,           XXXXXXX,        KC_DOT,         XXXXXXX, XXXXXXX,
        /*R4*/ HOME_I,     KC_Q,           XXXXXXX,        KC_COLON,       XXXXXXX, XXXXXXX,

        /*L1*/ HOME_D,     KC_C,           KC_Y,           KC_G,           XXXXXXX, XXXXXXX,
        /*L2*/ HOME_R,     KC_L,           KC_W,           KC_J,           XXXXXXX, XXXXXXX,
        /*L3*/ HOME_T,     KC_M,           KC_P,           KC_K,           XXXXXXX, XXXXXXX,
        /*L4*/ HOME_S,     KC_V,           XXXXXXX,        KC_X,           XXXXXXX, XXXXXXX,

        /*     Down        Pad             Up              Nail           Knuckle    DoubleDown*/
        /*RT*/ MO(NAV),    KC_SPACE,       KC_ESC,         KC_ENTER,      KC_LALT,   XXXXXXX,
        /*LT*/ MO(NUM),    KC_BSPC,        MO(SYMB),       XXXXXXX,       KC_TAB,    XXXXXXX
        ),
    [NAV] = LAYOUT(
        /*Center           North          East           South          West*/
        /*R1*/ KC_DOWN,    XXXXXXX,       XXXXXXX,       KC_LEFT,       KC_LEFT, XXXXXXX,
        /*R2*/ KC_UP,      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
        /*R3*/ KC_RIGHT,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
        /*R4*/ XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,

        /*L1*/ KC_LSFT,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
        /*L2*/ KC_LCTL,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
        /*L3*/ KC_LALT,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
        /*L4*/ KC_LGUI,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,

        /*     Down        Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,   XXXXXXX,
        /*LT*/ XXXXXXX,   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,   XXXXXXX
        ),
    [SYMB] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ KC_DLR,     KC_COLN,        XXXXXXX,        KC_EQL,         KC_UNDS, XXXXXXX,
        /*R2*/ KC_MINS,    KC_BSLS,        XXXXXXX,        KC_QUES,        KC_TILD, XXXXXXX,
        /*R3*/ KC_PLUS,    KC_SLSH,        XXXXXXX,        KC_EXLM,        XXXXXXX, XXXXXXX,
        /*R4*/ KC_PERC,    XXXXXXX,        CW_TOGG,        XXXXXXX,        XXXXXXX, XXXXXXX,

        /*L1*/ KC_PIPE,     KC_DQUO,       KC_AT,          XXXXXXX,        XXXXXXX, XXXXXXX,
        /*L2*/ KC_RPRN,     KC_RBRC,       KC_HASH,        XXXXXXX,        XXXXXXX, XXXXXXX,
        /*L3*/ KC_LPRN,     KC_LBRC,       XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX,
        /*L4*/ KC_GRV,      KC_CIRC,       XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX,

        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ XXXXXXX,         KC_SPACE,       XXXXXXX,       KC_BSPC,        KC_LALT,     XXXXXXX,
        /*LT*/ KC_LSFT,         KC_ENTER,       XXXXXXX,          KC_TAB,         KC_LCTL,     KC_CAPS
        ),
    [NUM] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ KC_4,       KC_7,           XXXXXXX,        KC_1,           KC_F, XXXXXXX,
        /*R2*/ KC_5,       KC_8,           XXXXXXX,        KC_2,           KC_0, XXXXXXX,
        /*R3*/ KC_6,       KC_9,           XXXXXXX,        KC_3,           XXXXXXX, XXXXXXX,
        /*R4*/ XXXXXXX,    XXXXXXX,        XXXXXXX,        KC_COLON,       XXXXXXX, XXXXXXX,

        /*L1*/ KC_LSFT,    XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX,
        /*L2*/ KC_LCTL,    XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX,
        /*L3*/ KC_LALT,    XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX,
        /*L4*/ KC_LGUI,    XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX,

        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ XXXXXXX,         KC_SPACE,       XXXXXXX,       KC_BSPC,        KC_LALT,     XXXXXXX,
        /*LT*/ KC_LSFT,         KC_ENTER,       XXXXXXX,          KC_TAB,         KC_LCTL,     KC_CAPS
        ),
    [MOUSE] = LAYOUT(
        /*Center           North           East            South           West*/

        /*R1*/ HOME_N,     MAGIC,          KC_QUOTE,       KC_H,           KC_F, XXXXXXX,
        /*R2*/ HOME_E,     KC_U,           KC_COLON,       KC_COMMA,       KC_B, XXXXXXX,
        /*R3*/ HOME_A,     KC_O,           XXXXXXX,        KC_DOT,         XXXXXXX, XXXXXXX,
        /*R4*/ HOME_I,     KC_Q,           XXXXXXX,        KC_COLON,       XXXXXXX, XXXXXXX,

        /*L1*/ HOME_D,     KC_C,           KC_Y,           KC_G,           KC_W, XXXXXXX,
        /*L2*/ HOME_R,     KC_L,           KC_P,           KC_J,           XXXXXXX, XXXXXXX,
        /*L3*/ HOME_T,     KC_M,           XXXXXXX,        KC_K,           XXXXXXX, XXXXXXX,
        /*L4*/ HOME_S,     KC_V,           XXXXXXX,        KC_X,           XXXXXXX, XXXXXXX,

        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ XXXXXXX,         KC_SPACE,       XXXXXXX,       KC_BSPC,        KC_LALT,     XXXXXXX,
        /*LT*/ KC_LSFT,         KC_ENTER,       XXXXXXX,          KC_TAB,         KC_LCTL,     KC_CAPS
        )
};

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    if (tap_hold_record->event.key.row == 0 || tap_hold_record->event.key.row == 5 ||
        other_record->event.key.row    == 0 || other_record->event.key.row    == 5) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    // update_tri_layer(NUM, NAV, FUNC); TODO: reinstate
    // update_tri_layer(SYMB, MOUSL, SYMB_MODL);
    // update_tri_layer(SYMB, MOUSR, SYMB_MODR);
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
            case M_SP_BUT:  SEND_STRING(/*,*/" but"); break;
            case M_HICH:    SEND_STRING(/*w*/"hich"); break;
            case M_UST:     SEND_STRING(/*j*/"ust"); break;
            case M_QUOT:
                tap_code16(KC_QUOT);
                tap_code16(KC_LEFT);
                break;
            case M_DQUO:
                tap_code16(KC_DQUO);
                tap_code16(KC_LEFT);
                break;
        }
    }
    // switch (keycode) {
    //     case MOUSE_TRACK_SCROLL: set_scrolling = record->event.pressed; break;
    //     case SET_MSTURDY: layer_move(MSTURDY); break;
    //     case SET_QWERTY: layer_move(QWERTY); break;
    // }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S: // left pinkie
            return TAPPING_TERM + 50;
        case HOME_I: // right pinkie
            return TAPPING_TERM + 50;
        case HOME_T:
            return TAPPING_TERM + 35;
        case HOME_A:
            return TAPPING_TERM + 35;
        case HOME_R:
            return TAPPING_TERM + 10;
        case HOME_E:
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
            case KC_QUOT: return M_QUOT;
            case KC_DQUO: return M_DQUO;
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

enum combo_events {
  SQUARE_BRACKET,
  PARENTHESIS,
  CURLY_BRACKETS,
  LESSTHAN_GREATERTHAN,
};

const uint16_t PROGMEM combo_full_squarebracket[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_full_parenthesis[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM combo_full_curlybracket[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM combo_full_lessthangreaterthan[] = {KC_LT, KC_GT, COMBO_END};
combo_t key_combos[] = {
  [SQUARE_BRACKET] = COMBO_ACTION(combo_full_squarebracket),
  [PARENTHESIS] = COMBO_ACTION(combo_full_parenthesis),
  [CURLY_BRACKETS] = COMBO_ACTION(combo_full_curlybracket),
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
            case LESSTHAN_GREATERTHAN:
                send_string("<>");
                tap_code16(KC_LEFT);
                break;
        }
    }
}
