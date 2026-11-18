/* 2026 Armando & Mr. Oaks - Sofle Choc VIA Configuration
 */
#pragma once

#define MASTER_LEFT

/****** Split Configuration */
#define SPLIT_USB_DETECT
#define SOFT_SERIAL_PIN D2                          // Explicit Serial connection pin
#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for Ikki)
#define SPLIT_LAYER_STATE_ENABLE                    // For layer-dependent key LEDs
#define SPLIT_WATCHDOG_ENABLE                       // Auto-recover slave if communication drops

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
// Desactivar efectos pesados de framebuffer y efectos no solicitados heredados de config.h base
#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif
#ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif
#ifdef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_SAT
#endif
#ifdef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_VAL
#endif

#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES                       // Reactive effects react to keypresses
#define RGB_MATRIX_SPLIT { 29, 29 }                 // 29 LEDs on each side
#define SPLIT_TRANSPORT_MIRROR                      // Sync animation state to slave
#define RGB_MATRIX_SLEEP                            // Turn off when suspended

// Efectos RGB Matrix requeridos activos
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
