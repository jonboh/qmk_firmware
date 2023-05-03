// Copyright 2023 Jon Bosque (@jonboh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
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
#define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW D4
#define ROTATIONAL_TRANSFORM_ANGLE -55
#define POINTING_DEVICE_INVERT_X
#define PMW33XX_CPI 1000
#define PMW33XX_LIFTOFF_DISTANCE 0x03
// Mouse Wheel Keys
#define MOUSEKEY_WHEEL_INTERVAL 60
#define MOUSEKEY_WHEEL_MAX_SPEED 12
#define MOUSEKEY_WHEEL_TIME_TO_MAX 20

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1000  // 1 seconds.
                                     //
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_INCREMENT 5

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT // when the default behavior changes to make this the default remove this line

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define PERMISIVE_HOLD // TODO: add explanation

