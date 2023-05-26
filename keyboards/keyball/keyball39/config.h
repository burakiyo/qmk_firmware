/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef __ASSEMBLER__
#include "config_common.h"
#include "apidef.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5957
#define PRODUCT_ID      0x0200
#define DEVICE_VER      0x0001
#define MANUFACTURER    Yowkees
#define PRODUCT         Keyball39
#define DESCRIPTION     A development board for wireless split keyboards

#define BMP_BOOTPIN_AS_RESET

#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
#define COMBO_COUNT 32

/* key matrix size */
#define MATRIX_ROWS_DEFAULT (4 * 2)
#define MATRIX_COLS_DEFAULT 6
#define THIS_DEVICE_ROWS (4 * 2)
#define THIS_DEVICE_COLS 6
#define IS_LEFT_HAND  false
#define BMP_DEFAULT_MODE SINGLE

/*
 * Enable mass storage when the switch connected following pins is pushed on boot.
 * No warranty
*/
// #define ALLOW_MSC_ROW_PIN 7
// #define ALLOW_MSC_COL_PIN 20

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS {20,19,18,17}
#define MATRIX_COL_PINS {7,8,9,10,11,12}
#define MATRIX_LAYOUT {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,255}
#define MATRIX_MASKED

#define KEYMAP_PRIOR_LOCALE 0
#define KEYMAP_ASCII 0

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define RGBLIGHT_SPLIT
#define G00 255 // Dummy for bin/qmk config generation
#define RGB_DI_PIN G00
#ifdef RGB_DI_PIN
  #define RGBLED_NUM_DEFAULT 48
  #define RGBLED_SPLIT { 24, 24 }
  #define RGBLIGHT_HUE_STEP 17
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 15
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
  /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
  #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
  /*==== use exp() and sin() ====*/
  #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
  #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 1

#define DEBUG_ACTION

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

// Split parameters
#define SOFT_SERIAL_PIN         D2
#define SPLIT_HAND_MATRIX_GRID  18, 12
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT       500

#define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO, KEYBALL_GET_MOTION, KEYBALL_SET_CPI

// RGB LED settings
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SPLIT    { 24, 24 }
#endif

#ifndef OLED_FONT_H
#    define OLED_FONT_H "keyboards/keyball/lib/glcdfont.c"
#endif

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif

// To squeeze firmware size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif /*__ASSEMBLER__*/
