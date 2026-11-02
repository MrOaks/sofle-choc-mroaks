# MCU Name
MCU = atmega32u4
# Bootloader Selection
BOOTLOADER = caterina

# Build Options
# 	Change yes to no to disable
#
BOOTMAGIC_ENABLE = no			# Enable Bootmagic Lite
MOUSEMAGIC_ENABLE = no			# Mouse Keys
EXTRAKEY_ENABLE = yes			# Audio control and System Control
CONSOLE_ENABLE = no				# Console for debug
COMMAND_ENABLE = no 			# Command for debug and configuration
NKRO_ENABLE = no 				# Enable N-Key Rollover
BACKLIGHT_ENABLE = no 			# Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no			# Enable keyboard RGB underglow
RGB_MATRIX_ENABLE  = WS2812
AUDIO_ENABLE = no				# Audio Output
ENCODER_MAP_ENABLE = yes		# Encoder functionality
OLED_ENABLE = yes				# OLED display
OLED_DRIVER = ssd1306 			# OLED display driver
WPM_ENABLE = no
TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes 				# Config Option Link Time Optimization
EXTRAFLAGS += -flto
