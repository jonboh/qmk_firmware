#pragma once

#define MASTER_RIGHT

#ifdef SOFT_SERIAL_PIN
    #undef SOFT_SERIAL_PIN
    #define SOFT_SERIAL_PIN D0
#else
    #define SOFT_SERIAL_PIN D0
#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1000  // 1 seconds.
                                     //
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 225
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_INCREMENT 5

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define PERMISIVE_HOLD // TODO: add explanation

// Special Characters
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

