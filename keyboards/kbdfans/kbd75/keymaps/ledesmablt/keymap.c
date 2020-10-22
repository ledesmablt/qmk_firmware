#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_MPLY, 
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME, 
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP, 
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN, 
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END, 
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       MO(1),    KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                                                                  DYN_REC_START1,  DYN_REC_START2,
                                                                                                                                      KC_TRNS,  KC_TRNS,  KC_TRNS, 
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RESET,    KC_TRNS, 
    KC_TRNS,  RGB_TOG,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_HUD,  BL_DEC,   BL_INC,   KC_TRNS,            KC_TRNS, 
    KC_TRNS,  RGB_M_P,  RGB_M_B,  RGB_SAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_HUI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS, 
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


void enable_macro_light(void) {
    rgblight_sethsv(HSV_SPRINGGREEN);
    rgblight_mode(5);
}

void enable_caps_light(void) {
    if (!rgblight_config.enable) {
        rgblight_enable();
    }
    rgblight_sethsv(HSV_GOLDENROD);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

bool isRecording = false;
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        enable_caps_light();
    } else if (isRecording) {
        enable_macro_light();
    } else {
        restore_user_rgb_settings();
    }
    return true;
};


// dynamic macros
void dynamic_macro_record_start_user(void) {
    isRecording = true;
    enable_macro_light();
}
void dynamic_macro_record_end_user(int8_t direction) {
    isRecording = false;
    restore_user_rgb_settings();
}
