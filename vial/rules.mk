# Things to enable
LTO_ENABLE = yes
WPM_ENABLE = yes
OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes
GRAVE_ESC_ENABLE = yes

# VIAL Settings
VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes
VIALRGB_ENABLE      = yes

RGBLIGHT_ENABLE     = no
TAP_DANCE_ENABLE    = no
MOUSEKEY_ENABLE     = no
COMBO_ENABLE        = no
KEY_OVERRIDE_ENABLE = no
QMK_SETTINGS        = no
EXTRAKEY_ENABLE     = no

# Imports
ifeq ($(OLED_ENABLE),yes)
	SRC += ./extra.c
endif