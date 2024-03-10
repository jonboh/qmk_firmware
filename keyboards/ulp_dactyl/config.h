// Copyright 2023 Jon Bosque (@jonboh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT


// Trackball
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN B1
#define SPI_MOSI_PIN B2
#define SPI_MISO_PIN B3
#define PMW33XX_CS_PIN B6
#define POINTING_DEVICE_MOTION_PIN D4
#define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW
#define ROTATIONAL_TRANSFORM_ANGLE 110
#define POINTING_DEVICE_INVERT_X
#define PMW33XX_CPI 600
// #define PMW33XX_LIFTOFF_DISTANCE 0x03
// Mouse Wheel Keys
#define TRACK_DIVISOR 8
#define MOUSE_EXTENDED_REPORT

/* #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD */
#define CAPS_WORD_IDLE_TIMEOUT 2000  // 2 seconds.
                                     //
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_INCREMENT 5

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define PERMISIVE_HOLD // TODO: add explanation

// Special Characters
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500 // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify an optional status LED by GPIO number which blinks when entering the bootloader
