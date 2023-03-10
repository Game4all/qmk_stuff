#include QMK_KEYBOARD_H

enum keymap_layers {
    layer_base = 0, // base layer
    layer_functions,  // function layer (Fn keys + media controls)
    layer_misc, // rgb settings layer + QMK boot key
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [layer_base] = LAYOUT_60_iso_arrow(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_NUBS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(layer_functions),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [layer_functions] = LAYOUT_60_iso_arrow(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______,                            MO(layer_misc),                   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [layer_misc] = LAYOUT_60_iso_arrow(
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,  _______,  QK_BOOT,
        _______,     RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______
    )
};

#define CAPS_LOCK_INDICATOR_COLOR 0xFF, 0xA5, 0x00
#define CAPS_LOCK_COLOR 0xFF, 0xA5, 0x00


bool rgb_matrix_indicators_user() {
    // indicator for caps lock.
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, 0x00, 0xFF, 0x00);
    } else {
        rgb_matrix_set_color(28, 0xFF, 0x00, 0x00);
    }
    return false;
}