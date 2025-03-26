#include "print.h"
#include <string.h>
#include "keycodes.h"
#include QMK_KEYBOARD_H

#define MSTURDY 0
#define QWERTY 1
#define NAV  2
#define SYMB 3
#define NUM  4
#define FUNC 5
#define MOUSL 6
#define MOUSR 7
// #define SYMB_MODL 8
// #define SYMB_MODR 9

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
    M_QUOT,
    M_DQUO,
    M_PIPE_AMPR,
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
#define HOME_J LGUI_T(KC_J)
#define HOME_G LALT_T(KC_G)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_A RALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)
#define HOME_H RALT_T(KC_H)
#define HOME_EQL RALT_T(KC_EQL)
#define HOME_COMM RGUI_T(KC_COMM)

#define HOME_1 RSFT_T(KC_1)
#define HOME_2 RCTL_T(KC_2)
#define HOME_3 RALT_T(KC_3)
#define HOME_4 RGUI_T(KC_4)

#define HOME_6 RSFT_T(KC_6)
#define HOME_7 RCTL_T(KC_7)
#define HOME_8 RALT_T(KC_8)
#define HOME_9 RGUI_T(KC_9)

#define HOME_F1 RSFT_T(KC_F1)
#define HOME_F2 RCTL_T(KC_F2)
#define HOME_F3 RALT_T(KC_F3)
#define HOME_F4 RGUI_T(KC_F4)

#define HOME_F6 LSFT_T(KC_F6)
#define HOME_F7 LCTL_T(KC_F7)
#define HOME_F8 LALT_T(KC_F8)
#define HOME_F9 LGUI_T(KC_F9)

#define HOME_F11 LALT_T(KC_F11)
#define HOME_F12 RALT_T(KC_F12)


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

#define MS_NORMAL_CPI 1000
#define MS_SNIPE_CPI 600

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case MOUSL:
    case MOUSR:
        pointing_device_set_cpi(MS_SNIPE_CPI);
        break;
    default:
        pointing_device_set_cpi(MS_NORMAL_CPI);
        break;
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case MOUSL:
    case MOUSR:
        pointing_device_set_cpi(MS_SNIPE_CPI);
        break;
    default:
        pointing_device_set_cpi(MS_NORMAL_CPI);
        break;
    }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MSTURDY] = LAYOUT(
            KC_V,     KC_M, KC_L, KC_C, KC_P,                                    KC_B, MAGIC, KC_U, KC_O, KC_Q,
            HOME_S, HOME_T, HOME_R, HOME_D, KC_Y,                           KC_F, HOME_N, HOME_E, HOME_A, HOME_I,
            KC_X,     KC_K, HOME_J, HOME_G, KC_W,                           KC_Z, HOME_H, HOME_COMM, KC_DOT, KC_SCLN,
            MO(MOUSL),          MO(NUM),  KC_DEL,                        KC_ESC, MO(NAV),               MO(MOUSR),
                                MO(SYMB), KC_BSPC,                              KC_SPC,
                                KC_TAB,                                         KC_ENT),
	[NAV] = LAYOUT(
	            ____, ____, ____, ____, ____,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END, ____,
	            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____,
	            ____,       ____, KC_LGUI, KC_LALT, ____,                                           ____,  ____,____,____, ____,
                        ____, MO(NUM),KC_DEL,                                             KC_ESC,KC_TRNS, ____,
                        ____, KC_BSPC,                                                   KC_SPC,
                        KC_TAB,                                                           KC_ENT),
	[SYMB] = LAYOUT(
	            KC_CIRC,KC_LBRC, KC_RBRC, KC_DQUO, KC_AT,               KC_TILD, MAGIC, KC_PERC, KC_AMPR, CW_TOGG,
	            KC_GRV, KC_LPRN, KC_RPRN, KC_PIPE, KC_UNDS,             KC_DLR, KC_COLN, KC_SLSH, KC_BSLS, UP(n_tilde,N_tilde),
              ____,   KC_LCBR, KC_RCBR, KC_QUOT, KC_HASH,            KC_ASTR, KC_EQL, KC_QUES, KC_EXLM, ____,
              MO(MOUSL),            ____,    KC_DEL,                   KC_ESC, ____,                    MO(MOUSR),
                                KC_TRNS, KC_BSPC,                              KC_SPC,
                                KC_TAB,                                        KC_ENT),
	[NUM] = LAYOUT(
	            ____, ____, ____, ____, ____,                          ____, MAGIC, KC_MINS, KC_PLUS, KC_PERC,
	            HOME_9, HOME_8, HOME_7, HOME_6, KC_5,              KC_0, HOME_1, HOME_2, HOME_3, HOME_4,
	            ____, ____, KC_LGUI, KC_LALT, ____,                          KC_ASTR, HOME_EQL, HOME_COMM, KC_DOT, KC_SCLN,
              ____,             KC_TRNS,KC_DEL,                       KC_ESC,MO(NAV),       ____,
                        ____, KC_BSPC,                                      KC_SPC,
                                KC_TAB,                                      KC_ENT),
	[FUNC] = LAYOUT(
	            ____, ____, KC_VOLD, KC_VOLU, KC_MUTE,                          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, ____,
	            HOME_F9, HOME_F8, HOME_F7, HOME_F6, KC_F5,              KC_F10, HOME_F1, HOME_F2, HOME_F3, HOME_F4,
	            ____, ____, KC_LGUI, HOME_F11,____,                                                  ____, HOME_F12, KC_RGUI, ____, ____,
                        ____, KC_TRNS,KC_DEL,                                            KC_ESC, KC_TRNS, ____,
                        ____, KC_BSPC,                                                   KC_SPC,
                        KC_TAB,                                                           KC_ENT),
	[MOUSL] = LAYOUT(
	            ____, MOUSE_TRACK_SCROLL, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3,  ____, ____, ____, ____, ____,
	                ____, ____, ____, ____, ____,                               ____, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
	               ____, ____, ____, ____, ____,                                ____, ____, ____, ____, ____,
                        KC_TRNS,  ____,                                             ____, ____,
                        MO(SYMB), KC_BSPC,                                                   KC_ESC,KC_SPC,
                        KC_TAB,    KC_DEL,                                                       KC_ENT),
	[MOUSR] = LAYOUT(
	            ____, ____, ____, ____, ____,                                 KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, MOUSE_TRACK_SCROLL, ____,
	            KC_RGUI, KC_RALT,KC_RCTL ,KC_RSFT, ____,                      ____, ____, ____, ____, ____,
	               ____, ____, ____, ____, ____,                                ____, ____, ____, ____, ____,
                       ____,  ____, KC_DEL,                                            KC_ESC,____, KC_TRNS,
                        MO(SYMB), KC_BSPC,                                                   KC_SPC,
                        KC_TAB,                                                           KC_ENT),
};


// Keyboard Logic

#include "features/achordion.h"


// Effects based on previously typed keys: https://getreuer.info/posts/keyboards/triggers/index.html#based-on-previously-typed-keys
#define RECENT_KEYS_TIMEOUT_MS 2000  // Timeout in milliseconds.
#define RECENT_SIZE 8    // Number of keys in `recent` buffer.

static uint16_t recent[RECENT_SIZE] = {KC_NO};
static uint16_t deadline = 0;

static void clear_recent_keys(void) {
  memset(recent, 0, sizeof(recent));  // Set all zeros (KC_NO).
}

// Handles one event. Returns true if the key was appended to `recent`.
static bool update_recent_keys(uint16_t keycode, keyrecord_t* record) {
  if (!record->event.pressed) { return false; }

  if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
    clear_recent_keys();  // Avoid interfering with hotkeys.
    return false;
  }

  // Handle tap-hold keys.
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return false; }
      keycode &= 0xff;  // Get tapping keycode.
  }

  switch (keycode) {
    case KC_A ... KC_SLASH:  // These keys type letters, digits, symbols.
    case KC_AT:
      break;

    case KC_LSFT:  // These keys don't type anything on their own.
    case KC_RSFT:
    case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
      return false;

    default:  // Avoid acting otherwise, particularly on navigation keys.
      clear_recent_keys();
      return false;
  }

  // Slide the buffer left by one element.
  memmove(recent, recent + 1, (RECENT_SIZE - 1) * sizeof(*recent));

  recent[RECENT_SIZE - 1] = keycode;
  deadline = record->event.time + RECENT_KEYS_TIMEOUT_MS;
  return true;
}

void housekeeping_task_user(void) {
  if (recent[RECENT_SIZE - 1] && timer_expired(timer_read(), deadline)) {
    clear_recent_keys();  // Timed out; clear the buffer.
  }
}



/* void pointing_device_init_user(void) { */
/*     set_auto_mouse_layer(MOUS); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer> */
/*     set_auto_mouse_enable(true);         // always required before the auto mouse feature will work */
/* } */

bool set_scrolling = false;
// Variables to store accumulated scroll values
int64_t scroll_accumulated_h = 0;
int64_t scroll_accumulated_v = 0;
#define TRACK_RESOLUTION  64


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (IS_LAYER_ON(SYMB)) { // for combinations with MOUSL/R to SYMB_MODL/R
        set_scrolling = false;
    }
    if (!IS_LAYER_ON(MOUSL) && !IS_LAYER_ON(MOUSR)){
        set_scrolling = false;
    }
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
    } else {
        // mouse_report.x = 1.15*mouse_report.x - 0.57*mouse_report.y;
        // mouse_report.y = 2*mouse_report.y - 1.73*mouse_report.x;
        // int64_t x = mouse_report.x;
        // int64_t y = mouse_report.y;
        // mouse_report.x = 3*(x + 0.3*y);
        // mouse_report.y = 1.5*y;
        // mouse_report.x = 1.5 * mouse_report.x;

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
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    update_tri_layer(NUM, NAV, FUNC);
      if (update_recent_keys(keycode, record)) {
        // Expand "@me" to my email address.
        if (recent[RECENT_SIZE - 3] == KC_AT &&
            recent[RECENT_SIZE - 2] == KC_M &&
            recent[RECENT_SIZE - 1] == KC_E) {
          SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) "jon.bosque.hernando@gmail.com");
          return false;
        }
        if (recent[RECENT_SIZE - 4] == KC_AT &&
            recent[RECENT_SIZE - 3] == KC_J &&
            recent[RECENT_SIZE - 2] == KC_O &&
            recent[RECENT_SIZE - 1] == KC_B
            ) {
          SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) "jon.bosque@optimitive.com");
          return false;
        }
      }

    // update_tri_layer(SYMB, MOUSL, SYMB_MODL);
    // update_tri_layer(SYMB, MOUSR, SYMB_MODR);
    if (!process_achordion(keycode, record)) {return false;}


    // Shift+Backspace= Delete, see https://getreuer.info/posts/keyboards/macros3/index.html#shift-backspace-delete
    switch (keycode) {
        case KC_BSPC: {
          static uint16_t registered_key = KC_NO;
          if (record->event.pressed) {  // On key press.
            const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
            uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
            uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
            if (shift_mods) {  // At least one shift key is held.
              registered_key = KC_DEL;
              // If one shift is held, clear it from the mods. But if both
              // shifts are held, leave as is to send Shift + Del.
              if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
                del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
                unregister_mods(MOD_MASK_SHIFT);
              }
            } else {
              registered_key = KC_BSPC;
            }

            register_code(registered_key);
            set_mods(mods);
          } else {  // On key release.
            unregister_code(registered_key);
          }
        } return false;
    }
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
            case M_SP_BUT:  SEND_STRING(/*,*/" but"); break;
            case M_HICH:    SEND_STRING(/*w*/"hich"); break;
            case M_UST:     SEND_STRING(/*j*/"ust"); break;
            case M_PIPE_AMPR:
                tap_code16(KC_BSPC);
                tap_code16(KC_AMPR);
                return false;
            case M_QUOT:
                tap_code16(KC_QUOT);
                tap_code16(KC_LEFT);
                break;
            case M_DQUO:
                tap_code16(KC_DQUO);
                tap_code16(KC_LEFT);
                break;
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
        case HOME_S: // left pinkie
        case HOME_I: // right pinkie
        case HOME_4:
        case HOME_F4:
        case HOME_9:
        case HOME_F9:
            return TAPPING_TERM + 50;
        case HOME_T:
        case HOME_A:
        case HOME_3:
        case HOME_F3:
        case HOME_8:
        case HOME_F8:
            return TAPPING_TERM + 35;
        case HOME_J:
        case HOME_G:
        case HOME_H:
        case HOME_COMM:
        case HOME_EQL:
        case HOME_F11:
        case HOME_F12:
            return TAPPING_TERM + 20;
        case HOME_R:
        case HOME_E:
        case HOME_2:
        case HOME_F2:
        case HOME_7:
        case HOME_F7:
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
            case KC_PIPE: return M_PIPE_AMPR;
            case KC_QUOT: return M_QUOT;
            case KC_DQUO: return M_DQUO;
            case KC_MINS: return KC_EQL;
            case KC_PLUS: return KC_EQL;
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
  AMPERSAND,
  LESSTHAN_GREATERTHAN,
};

const uint16_t PROGMEM combo_full_squarebracket[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_full_parenthesis[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM combo_full_curlybracket[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM combo_full_ampersand[] = {KC_RPRN, KC_PIPE, COMBO_END};
const uint16_t PROGMEM combo_full_lessthangreaterthan[] = {KC_LT, KC_GT, COMBO_END};
combo_t key_combos[] = {
  [SQUARE_BRACKET] = COMBO_ACTION(combo_full_squarebracket),
  [PARENTHESIS] = COMBO_ACTION(combo_full_parenthesis),
  [CURLY_BRACKETS] = COMBO_ACTION(combo_full_curlybracket),
  [AMPERSAND] = COMBO_ACTION(combo_full_ampersand),
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
            case AMPERSAND:
                send_string("&");
                break;
            case LESSTHAN_GREATERTHAN:
                send_string("<>");
                tap_code16(KC_LEFT);
                break;
        }
    }
}
//#endif /* ifdef COMBO_ENABLE */

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
#endif
