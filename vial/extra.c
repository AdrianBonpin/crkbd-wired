#include QMK_KEYBOARD_H
#include "./layers.h"

// Initialize Keyboard rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // If slave, rotate 180 deg
    }
    return rotation;
}

// Render Spacer
static void render_space(void) {
    switch (get_highest_layer(layer_state)) {
        case _FPS:
        case _FPS_EXTRA:
            oled_write_P(PSTR("+-------------------+"), false);
            break;
        default:
            oled_write_P(PSTR("+------+------------+"), false);
            break;
    }
}

static void render_name(void) {
    oled_write_P(PSTR("+------+------crkbd-+"), false);
}

// Render Layer State
static void cur_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWRTY:
            oled_write_P(PSTR("| BASE | LETTERS    |"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("| BASE | NUMBERS    |"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("| BASE | FUNCTIONS  |"), false);
            break;
        case _FPS:
            oled_write_P(PSTR("|      ~ FPS ~      |"), false);
            oled_write_P(PSTR("|  M O V E M E N T  |"), false);
            break;
        case _FPS_EXTRA:
            oled_write_P(PSTR("|      ~ FPS ~      |"), false);
            oled_write_P(PSTR("| E Q U I P M E N T |"), false);
            break;
        default:
            oled_write_P(PSTR("|        NaN        |"), false);
            break;
    }
}

static void wpm_caps(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("| WPM  | "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    oled_write_P(led_state.caps_lock ? PSTR("   CAPS |") : PSTR("        |") , false);
}

void oled_splash(void) {
    static const char PROGMEM splash[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(splash, false);

}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _FPS:
            case _FPS_EXTRA:
                render_space();
                cur_layer_state();
                render_space();
                break;
            default:
                cur_layer_state();
                render_space();
                wpm_caps();
                render_name();
                break;
        }
    } else {
        oled_splash();
    }
    return false;
}