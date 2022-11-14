/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    FUNC,
    TOP,
    FRNT,
};

#define FN_FUNC LT(FUNC, KC_PSCR)


// Encoders - Encoder Map ================================================= //
// https://docs.qmk.fm/#/feature_encoders?id=encoder-map                    //

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FUNC]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [TOP]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [FRNT]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default
    [BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        FN_FUNC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function
    [FUNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_RBT,            KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           OSL(TOP),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           OSL(FRNT),
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,  TO(BASE),
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______,  _______
    ),

    // Top
    [TOP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // FRNT
    [FRNT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    
};
// clang-format on

// RGB Matrix - Callbacks ================================================= //
// https://docs.qmk.fm/#/feature_rgb_matrix?id=callbacks                    //

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Show Caps Lock state:
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
}

void rgb_matrix_indicators_user(void) {        
    if (is_caps_word_on()) {
        // Show Caps Word state
        rgb_matrix_set_color_all(RGB_MAGENTA);
    } else {
        // Show active layear
        uint8_t layer = get_highest_layer(layer_state|default_layer_state);

        switch(layer) {
            case FUNC:
                rgb_matrix_set_color_all(RGB_CYAN);
                break;
            case TOP:
                rgb_matrix_set_color_all(RGB_ORANGE);
                break;   
            case FRNT:
                rgb_matrix_set_color_all(RGB_CHARTREUSE);
                break;                     
            default:
                break;
        }
    }

}