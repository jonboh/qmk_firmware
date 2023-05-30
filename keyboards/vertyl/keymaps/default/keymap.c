#include "keycode.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H

#define MSTURDY 0
#define DVORAK 1
#define NAV  2
#define SYMB 3
#define NUM  4
#define FUNC 5
#define MEDI 6
#define MOUS 7

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  EXIT,
  SCOPE,
  SELWORD,
  TMUXESC,
  SRCHSEL,
  USRNAME,
  DASH,
  ARROW,
  THMBUP,
  REPEAT,
  ALTREP,
  M_ION,
  M_NION,
  M_MENT,
  M_QUEN,
  M_TMENT,
  M_THE,
  M_UPDIR,
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
            HOME_S, HOME_T, HOME_R, HOME_D, KC_Y,            KC_F, HOME_N, HOME_E, HOME_A, HOME_I,
            /* KC_S, KC_T, KC_R, KC_D, KC_Y,                       KC_F, KC_N, KC_E, KC_A, KC_I, */
            KC_X, KC_K, KC_J, KC_G, KC_W,                                KC_Z, KC_H, KC_COMM, KC_DOT, KC_SCLN,
                                           MO(SYMB), MO(MOUS),                                            KC_ESC,
                      MO(NUM), KC_BSPC,KC_DEL,                                                  KC_ENT,KC_SPC,MO(NAV),
                                MO(MEDI),                                                  KC_TAB),
	[DVORAK] = LAYOUT(
            KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,                                    KC_F, KC_G, KC_C, KC_R, KC_L,
            LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I,            KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),
            XP(n_tilde,N_tilde), KC_Q, KC_J, KC_K, KC_X,                                KC_B, KC_M, KC_W, KC_V, KC_Z,
                                           MO(SYMB), MO(MOUS),                                            KC_ESC,
                      MO(NUM), KC_BSPC,KC_DEL,                                                  KC_ENT,KC_SPC,MO(NAV),
                                MO(MEDI),                                                  KC_TAB),
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
            ____, ____, ____, ____, ____,                                                   ____, ____, ____, ____, ____,
            LGUI_T(KC_F2), LALT_T(KC_F3), LCTL_T(KC_F4), LSFT_T(KC_F5), KC_F6,              KC_F7, RSFT_T(KC_F8), RCTL_T(KC_F9), LALT_T(KC_F10), KC_F11,
            KC_F1, ____, ____, ____, ____,                                                  ____, ____, ____, ____, KC_F12,
                                      ____,____,                                            ____,
                                ____, ____,____,                                      ____, ____,____,
                                ____,                                                       ____),
	[MEDI] = LAYOUT(
            TO(DVORAK), ____, ____, ____, ____,                                   ____, ____, ____, ____, TO(MSTURDY),
            ____, ____, KC_VOLD, KC_VOLU, KC_MUTE,                          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, ____,
            KC_TRNS, DT_DOWN, DT_UP, ____, ____,                               ____, ____, ____, ____, ____,
                                     ____,____,                               ____,
                                ____,____,____,                         ____,____,____,
                                ____,                                     ____),
	[MOUS] = LAYOUT(
            ____, ____, ____, ____, ____,                                    ____, ____, ____, ____, ____,
           KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,                        ____, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, ____,
            ____, ____, ____, ____, ____,                                   KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, ____,
                                     ____, KC_TRNS,                        ____,
                                ____,____,____,                        ____,____,____,
                              ____,                                          ____),
};

// Keyboard Logic

#include "features/achordion.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(NUM, NAV, FUNC);
    if (!process_achordion(keycode, record)) {return false;}

  if (record->event.pressed) {
    switch (keycode) {
      // Macros invoked through the MAGIC key.
      case M_ION:     SEND_STRING(/*i*/"on"); break;
      case M_NION:    SEND_STRING(/*n*/"ion"); break;
      case M_MENT:    SEND_STRING(/*m*/"ent"); break;
      case M_QUEN:    SEND_STRING(/*q*/"uen"); break;
      case M_TMENT:   SEND_STRING(/*t*/"ment"); break;
      case M_THE:     SEND_STRING(/* */"the"); break;
      case M_UPDIR:   SEND_STRING(/*.*/"./"); break;
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
      case HOME_A:  // A -> O
        return KC_O;
      case KC_C:  // C -> Y
        return KC_Y;
      case HOME_D:  // D -> Y
        return KC_Y;
      case HOME_E:  // E -> U
        return KC_U;
      case KC_G:  // G -> Y
        return KC_Y;
      case HOME_I:  // I -> ON
        return M_ION;
      case KC_L:  // L -> K
        return KC_K;
      case KC_M:  // M -> ENT
        return M_MENT;
      case HOME_N:  // N -> ION
        return M_NION;
      case KC_N:
        return KC_N;
      case KC_O:  // O -> A
        return KC_A;
      case KC_P:  // P -> Y
        return KC_Y;
      case KC_Q:  // Q -> UEN
        return M_QUEN;
      case HOME_R:  // R -> L
        return KC_L;
      case HOME_S:  // S -> K
        return KC_K;
      case HOME_T:  // T -> MENT
        return M_TMENT;
      case KC_U:  // U -> E
        return KC_E;
      case KC_Y:  // Y -> P
        return KC_P;

      case KC_SPC:  // spc -> THE
        return M_THE;
      case KC_DOT:  // . -> ./
        return M_UPDIR;
        }
        return KC_NO;
    }
  /* } else if ((mods & MOD_MASK_CTRL)) { */
  /*   switch (keycode) { */
  /*     case HOME_A:  // Ctrl+A -> Ctrl+C */
  /*       return C(KC_C); */
  /*     case KC_C:  // Ctrl+C -> Ctrl+V */
  /*       return C(KC_V); */
  /*   } */
  /* } */
  return KC_TRNS;
}

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   //debug_matrix=true; */
/*   debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */
