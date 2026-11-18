/* 2026 Armando & Mr. Oaks - Sofle Choc VIA Configuration
 */
#pragma once

#define MASTER_LEFT

/****** Split Configuration */
#define SPLIT_USB_DETECT
#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for Ikki)
#define SPLIT_LAYER_STATE_ENABLE                    // For layer-dependent key LEDs

/****** VIA Dynamic Keymap */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/****** Features: Tapping */
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 150
#define TAP_CODE_DELAY 10

/****** Hardware: LEDs */
#define RGBLED_NUM 58

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES                       // Reactive effects react to keypresses
#define RGB_MATRIX_SPLIT { 29, 29 }                 // 29 LEDs on each side
#define SPLIT_TRANSPORT_MIRROR
#define RGB_MATRIX_SLEEP                            // Turn off when suspended

// Enabled RGB Matrix effects (Selective Flash Optimization: Rainbow, Wave, Breathing, Reactive)
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_CYCLE_ALL                // Arcoiris completo (Rainbow Cycle)
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT         // Onda arcoiris horizontal (Wave)
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE    // Reactivo por pulsacion
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#ifdef OLED_FONT_H
#undef OLED_FONT_H
#endif
#define OLED_FONT_H "lib/font.c"
#endif // OLED_ENABLE
