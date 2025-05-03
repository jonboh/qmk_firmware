// Copyright 2023 Jon Bosque (@jonboh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT


// Trackball
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN B1 // OK
#define SPI_MOSI_PIN B2 // OK
#define SPI_MISO_PIN B3 // OK
#define CIRQUE_PINNACLE_SPI_CS_PIN B6
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_3X
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
// #define POINTING_DEVICE_ROTATION_90

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

#define CHORDAL_HOLD
