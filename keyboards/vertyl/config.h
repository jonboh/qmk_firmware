// Copyright 2023 Jon Bosque (@jonboh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT

#define MATRIX_ROWS 10
#define MATRIX_COLS 5
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { F4, F5, F6, F7, D1 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }
// Set TRRS connection pin
#define USE_SERIAL

#ifdef SOFT_SERIAL_PIN
    #undef SOFT_SERIAL_PIN
    #define SOFT_SERIAL_PIN D0
#else
    #define SOFT_SERIAL_PIN D0
#endif

// Trackball
#define PMW33XX_CS_PIN B6
#define POINTING_DEVICE_MOTION_PIN D4
#define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW
#define ROTATIONAL_TRANSFORM_ANGLE 10
#define POINTING_DEVICE_INVERT_X
#define PMW33XX_CPI 1000
#define PMW33XX_LIFTOFF_DISTANCE 0x03
// Mouse Wheel Keys
#define TRACK_DIVISOR 8
/* #define MOUSE_EXTENDED_REPORT */
// Auto activation
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_TIME 1000
#define AUTO_MOUSE_DELAY 0

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 2000  // 2 seconds.
                                     //
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_INCREMENT 5

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define PERMISIVE_HOLD // TODO: add explanation

// Special Characters
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// gasping for size
#define NO_ACTION_ONESHOT
#define RGBLIGHT_MAX_LAYERS 1
