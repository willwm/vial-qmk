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

#define L3_PSCR LT(3,KC_PSCR)

// Encoders - Encoder Map ================================================= //
// https://docs.qmk.fm/#/feature_encoders?id=encoder-map                    //

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
    //      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
    //      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
    // LT(3,...)     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
    //      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
    //      Ct_L     Alt_L    Win_L                               SPACE                               Win_R    Alt_R    Ct_R     Left     Down     Right
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        L3_PSCR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           RGB_SPI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           RGB_VAD,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_SAI,  RGB_SPD,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_HUD, RGB_SAD,  RGB_HUI
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_LOCK,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_CAPS, _______,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______,  _______
    ),
};
// clang-format on



// RGB Matrix - Callbacks ================================================= //
// https://docs.qmk.fm/#/feature_rgb_matrix?id=callbacks                    //

void caps_lock_indicator(uint8_t led_min, uint8_t led_max)  {
    
}

// https://docs.qmk.fm/#/feature_rgb_matrix?id=indicator-examples
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

// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgb_matrix/rgb_matrix.h#L133
void rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);

    switch(layer) {
        case 3:
            rgb_matrix_set_color_all(RGB_CYAN);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
        case 1:
            rgb_matrix_set_color_all(RGB_CHARTREUSE);
            break;
        default:
            break;
    }      
}