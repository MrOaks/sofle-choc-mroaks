MCU = atmega32u4
BOOTLOADER = caterina

LTO_ENABLE = yes
SPLIT_KEYBOARD = yes

# VIA & Subsystems (Fully enabled on both sides for 100% RPC symmetry)
VIA_ENABLE = yes

# Sofle Features
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

# RGB Matrix
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812

# Flash Optimization
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = no
MOUSEKEY_ENABLE = no
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes
