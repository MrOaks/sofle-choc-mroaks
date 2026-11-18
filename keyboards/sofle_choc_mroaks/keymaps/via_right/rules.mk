MCU = atmega32u4
BOOTLOADER = caterina

LTO_ENABLE = yes
SPLIT_KEYBOARD = yes

# VIA & EEPROM (Disabled on slave right half to save Flash for Ikki OLED animation)
VIA_ENABLE = no
EEPROM_ENABLE = no

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
