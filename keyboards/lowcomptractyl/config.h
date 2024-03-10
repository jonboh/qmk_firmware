// Copyright 2023 Jon Bosque (@jonboh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT

#define MATRIX_ROWS 10
#define MATRIX_COLS 5
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { 2, 3, 4, 5, 6 }
#define MATRIX_COL_PINS { 29, 28, 27, 26, 21 }
// Set TRRS connection pin
/* #define USE_SERIAL */

/* #ifdef SOFT_SERIAL_PIN */
    /* #undef SOFT_SERIAL_PIN */
/*     #define SOFT_SERIAL_PIN D0 */
/* #else */
/*     #define SOFT_SERIAL_PIN D0 */
/* #endif */
#define SERIAL_PIO_USE_PIO1
#undef SOFT_SERIAL_PIN
#define SERIAL_USART_DRIVER SIOD0
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN	GP1

// Trackball
#define PMW33XX_CS_PIN 1
#define POINTING_DEVICE_MOTION_PIN 9
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
#define AUTO_MOUSE_TIME 0
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

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify an optional status LED by GPIO number which blinks when entering the bootloader
