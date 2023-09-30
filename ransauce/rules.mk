# Things to enable
LTO_ENABLE = yes
WPM_ENABLE = yes
OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes
GRAVE_ESC_ENABLE = yes

# Things to disable [Memory Save]
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
RGBLIGHT_ENABLE = no
VIA_ENABLE = no

# Imports
ifeq ($(OLED_ENABLE),yes)
	SRC += ./extra.c
endif