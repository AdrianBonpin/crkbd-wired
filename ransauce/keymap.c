#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC, 
        KC_CAPS,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_DEL,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_END, 
                                                KC_LCTL,    MO(1),      KC_SPC,                 KC_ENT,     MO(2),      KC_RGUI
    ),
    [1] = LAYOUT(
        KC_ESC,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        KC_LALT,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_LBRC,    KC_RBRC,    KC_UP,      KC_APP,     KC_QUOT,    KC_EQL,
        KC_LSFT,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BSPC,                KC_GRV,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_BSLS,    KC_PSCR,
                                                KC_TRNS,    KC_TRNS,    KC_TRNS,                LALT(KC_SPC),MO(3),     KC_TRNS
    ),
    [2] = LAYOUT(
        KC_F1,          KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_TAB,         KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                KC_TRNS,    KC_LALT,    KC_TRNS,                KC_NO,      KC_TRNS,    KC_TRNS
    ),
    [3] = LAYOUT(
        KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  RGB_TOG,    RGB_VAI,    RGB_HUI,    RGB_SAI,    RGB_SPI,    RGB_MOD,
        KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                  RGB_M_P,    RGB_VAD,    RGB_HUD,    RGB_SAD,    RGB_SPD,    RGB_RMOD,
                                                KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_TRNS,    KC_NO
    )
};