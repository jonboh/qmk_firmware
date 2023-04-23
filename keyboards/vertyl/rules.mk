# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
LTO_ENABLE = yes            # Makes firmware smaller
CAPS_WORD_ENABLE = yes		# caps word with LShift+RShift
COMMAND_ENABLE = no 		# Disables LShift+RShift activating command
DYNAMIC_TAPPING_TERM_ENABLE = yes

# Trackball
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3389
#MOUSE_SHARED_EP = no # see https://qmk.github.io/qmk_mkdocs/master/en/config_options/#usb-endpoint-limitations

SRC += features/achordion.c

