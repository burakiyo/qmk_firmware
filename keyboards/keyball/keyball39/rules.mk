# MCU name
MCU_FAMILY = NRF52
MCU_SERIES = NRF52840
MCU_LDSCRIPT = nrf52840_ao
MCU = cortex-m4
CUSTOM_MATRIX = yes # This flag should be on for nrf52

# Link Time Optimization required for size.
LTO_ENABLE = yes

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration(+1000)
MOUSE_SHARED_EP = no		# Should be disabled for BLE Micro Pro
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = yes        # Commands for debug and configuration

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
HD44780_ENABLE = no 		# Enable support for HD44780 based LCDs (+400)
COMBO_ENABLE = yes

# Keyball39 is split keyboard.
SPLIT_KEYBOARD = no

# Optical sensor driver for trackball.
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
SRC += drivers/pmw3360/pmw3360.c
# QUANTUM_LIB_SRC += spi_master.c # Optical sensor use SPI to communicate

# This is unnecessary for processing KC_MS_BTN*.
MOUSEKEY_ENABLE = yes

# Enabled only one of RGBLIGHT and RGB_MATRIX if necessary.
RGBLIGHT_ENABLE = no        # Enable RGBLIGHT
RGBLIGHT_DRIVER = WS2812
RGB_MATRIX_ENABLE = no      # Enable RGB_MATRIX (not work yet)
RGB_MATRIX_DRIVER = WS2812

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

# To support OLED
OLED_ENABLE = yes                # Please Enable this in each keymaps.
SRC += lib/oledkit/oledkit.c    # OLED utility for Keyball series.

# Include common library
SRC += lib/keyball/keyball.c

# Disable other features to squeeze firmware size
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no