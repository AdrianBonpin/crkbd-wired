#include QMK_KEYBOARD_H

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // If slave, rotate 180 deg
    }
    return rotation;
}

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base"), false);
            break;
        case 1:
            oled_write_P(PSTR("Num + Nav"), false);
            break;
        case 2:
            oled_write_P(PSTR("Func"), false);
            break;
        case 3:
            oled_write_P(PSTR("Extra"), false);
            break;
        default:
            oled_write_P(PSTR("undefined"), false);
            break;
    }
    oled_write_ln_P(PSTR(""), false);
}

static void oled_render_caps(void) {
    oled_write_P(PSTR("CPSLK: "), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("On   ") : PSTR("Off  ") , false);
    oled_write_P(PSTR(" "), false);
}

static void oled_render_wpm(void) {
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    oled_write_ln_P(PSTR(""), false);
}

static void oled_render_name(void) {
    oled_write_P(PSTR("~ RanSauce ~"), false);
}

__attribute__((weak)) void oled_render_logo(void) {
    static const char PROGMEM splash[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(splash, false);
}

bool oled_task_kb(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_caps();
        oled_render_wpm();
        oled_render_name();
    } else {
        oled_render_logo();
    }
    return false;
}