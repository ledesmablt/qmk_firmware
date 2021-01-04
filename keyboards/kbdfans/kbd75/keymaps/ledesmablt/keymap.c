#include QMK_KEYBOARD_H

// layer constants
#define _BASE 0
#define _FN1 1
#define _VIM 5
#define _VIM2 6
#define _MOUS 8

bool is_recording  = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_MPLY,
    LT(_VIM, KC_GRV),
              KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  LT(_VIM, KC_BSLS),  KC_PGUP,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(_FN1), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(_FN1), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_FN1] = LAYOUT(
    DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                                                                  DYN_REC_START1,  DYN_REC_START2,
                                                                                                                                      KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  TO(_BASE),TO(_FN1), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RESET,    KC_TRNS,
    KC_TRNS,  RGB_TOG,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_HUD,  KC_MPRV,  KC_MNXT,  TO(_VIM),           KC_TRNS,
    KC_TRNS,  RGB_M_P,  RGB_M_B,  RGB_SAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_VIM), KC_TRNS,  RGB_HUI,  TO(_MOUS),KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),


  [_VIM] = LAYOUT(
    TO(_BASE),KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  TO(_BASE),KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PGUP,  TO(_BASE),KC_NO,    LSFT(KC_F3),
                                                                                                                  KC_NO,    KC_NO,    KC_NO,              KC_TRNS,
    KC_TRNS,  KC_NO,    KC_NO,    KC_PGDN,  KC_WFWD,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    KC_NO,                        KC_ENT,   KC_TRNS,
    LT(_VIM2, KC_NO),
              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_WBAK,  KC_F3,    KC_NO,    KC_NO,    KC_NO,    LCTL(KC_F),
                                                                                                                            LT(_VIM2, KC_TRNS), KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  // shifted vim
  [_VIM2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_END,   KC_NO,    KC_HOME,  KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
    LSFT(KC_TAB),
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F3,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  LSFT(KC_F3),
                                                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_MOUS] = LAYOUT(
    TO(_BASE),KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,
                                            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MS_WH_UP,
                                                                                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MS_BTN2,         KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_MS_WH_DOWN,
                                            KC_NO,    KC_NO,
                                                                KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,
                                                                                                        KC_NO,    KC_NO,                        KC_MS_BTN1,
                                                                                                                                                          KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};


// Based off adamdehaven's config
extern rgblight_config_t rgblight_config;
static bool RGB_user_wants_enabled;
uint16_t RGB_current_mode;
uint16_t RGB_current_hue;
uint16_t RGB_current_sat;
uint16_t RGB_current_val;

// customs
void enable_mouse_light(void) {
    rgblight_sethsv(HSV_ORANGE);
}

void enable_vim_light(void) {
    rgblight_sethsv(HSV_TEAL);
}

void enable_macro_light(void) {
    rgblight_sethsv(HSV_SPRINGGREEN);
    rgblight_mode(5);
}

void enable_caps_light(void) {
    if (!rgblight_config.enable) {
        rgblight_enable();
    }
    rgblight_sethsv(HSV_GOLD);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}


// Setup RGB
void keyboard_post_init_user(void) {
    RGB_user_wants_enabled = rgblight_config.enable;
    RGB_current_mode = rgblight_config.mode;
    RGB_current_hue  = rgblight_config.hue;
    RGB_current_sat  = rgblight_config.sat;
    RGB_current_val  = rgblight_config.val;
};

// Restore user settings
void restore_user_rgb_settings(void) {
    // First, enable RGB
    if (RGB_user_wants_enabled && !rgblight_config.enable) {
        rgblight_enable();
    } else if (!RGB_user_wants_enabled && rgblight_config.enable) {
        rgblight_disable();
    }

    // Restore settings
    rgblight_sethsv(RGB_current_hue, RGB_current_sat, RGB_current_val); // Restore underglow RGB color
    rgblight_mode(RGB_current_mode); // Restore RGB mode
};

// Fire on keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_M_P:
            if (!record->event.pressed) {
                RGB_user_wants_enabled = rgblight_config.enable;
                RGB_current_mode = rgblight_config.mode;
            }
        case RGB_M_B:
            if (!record->event.pressed) {
                RGB_user_wants_enabled = rgblight_config.enable;
                RGB_current_mode = rgblight_config.mode;
            }
        case RGB_TOG:
            if (!record->event.pressed) {
                // on keyup
                RGB_user_wants_enabled = rgblight_config.enable;
            }
            break;
        case RGB_MOD:
            if (!record->event.pressed) {
                // on keyup
                RGB_current_mode = rgblight_config.mode;
            }
            break;
        case RGB_HUI:
        case RGB_HUD:
            if (!record->event.pressed) {
                // on keyup
                RGB_current_hue = rgblight_config.hue;
            }
            break;
        case RGB_SAI:
        case RGB_SAD:
            if (!record->event.pressed) {
                // on keyup
                RGB_current_sat = rgblight_config.sat;
            }
            break;
        case RGB_VAI:
        case RGB_VAD:
            if (!record->event.pressed) {
                // on keyup
                RGB_current_val = rgblight_config.val;
            }
            break;
    }
    return true;
};


bool led_update_user(led_t led_state) {
    if (layer_state_is(_VIM)) {
        enable_vim_light();
    } else if (layer_state_is(_MOUS)) {
        enable_mouse_light();
    } else if (led_state.caps_lock) {
        enable_caps_light();
    } else if (is_recording) {
        enable_macro_light();
    } else {
        restore_user_rgb_settings();
    }
    return true;
};


// dynamic macros
void dynamic_macro_record_start_user(void) {
    is_recording = true;
    enable_macro_light();
}
void dynamic_macro_record_end_user(int8_t direction) {
    is_recording = false;
    restore_user_rgb_settings();
}
