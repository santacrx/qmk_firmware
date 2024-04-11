/* Copyright 2023 @ santacrx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * This program is based on the base offered by Keychron and any other 
 * sources as identified in the comments and README. I'm just a hobbyist, 
 * not responisuble if you use any of this and brick your keeb. 
 */

#include QMK_KEYBOARD_H
//#include "keychron_common.h"

// clang-format off

enum layers{
    _BASE,
    _FN1,
    _FN2,
    _NUM
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_89(
        _______,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TG(_NUM),           KC_PSCR,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            RSFT_T(KC_ENT),           KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RCTL,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   MO(_FN1),                      KC_SPC,             MO(_FN2),                     KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FN1] = LAYOUT_ansi_89(
        KC_MUTE,  KC_CALC,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PGUP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_PGDN,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [_FN2] = LAYOUT_ansi_89(
        KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            _______,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            _______,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             _______,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   _______,                       KC_SPC,             _______,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_NUM] = LAYOUT_ansi_89(
        KC_MS_BTN1,   RGB_TOG,  		RGB_HUD,  	   RGB_HUI,  	   RGB_SAD,    RGB_SAI,  RGB_VAD,   RGB_VAI,  RGB_RMOD,  RGB_MOD,   KC_NO,  	KC_NO,    KC_NO,   KC_NO,   _______,            _______,
        KC_MS_ACCEL0,  KC_NO,        KC_NO,         KC_NO,        KC_NO,      KC_NO,    KC_NO,     KC_NO,   KC_PSLS,   KC_PAST,  KC_PMNS,   KC_NO,   _______, _______,  _______,            _______,
        KC_MS_ACCEL1, _______,    	 KC_NO,        KC_MS_UP,  	  KC_NO,	    KC_NO,    KC_NO,     KC_P7,    KC_P8,     KC_P9,   KC_PPLS,   KC_NO,    KC_NO,    KC_NO,  _______,            _______,
        KC_MS_ACCEL2,  KC_NO,   	 KC_MS_LEFT,    KC_MS_DOWN,   KC_MS_RIGHT,  KC_NO,    KC_NO,     KC_P4,    KC_P5,     KC_P6,   KC_PPLS,   KC_NO,    KC_NO,            _______,            _______,
         KC_NO,   	  _______,            		      KC_NO,   	    KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_P0,     KC_P1,    KC_P2,    KC_P3,   KC_PENT,  KC_NO,    KC_NO,   _______,
        KC_NUM,   	  _______,  		_______,       		     	     _______,    _______,  _______,                         KC_P0,             KC_PDOT,                     _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT) },
    [_FN1]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN2] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUM]   = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) }
};
#endif // ENCODER_MAP_ENABLE

// PARTY_MODE LIGHTS
// trying moving things here from rg_matrix_user.inc to see if it compiles

static HSV party_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].x - time;
    return hsv;
}

bool party_effect_i(effect_params_t* params, HSV effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    
    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);

    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t i = g_led_config.matrix_co[row][col];

            if (i >= led_min && i < led_max && i != NO_LED && HAS_FLAGS(g_led_config.flags[i], 0x04) &&
            keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                RGB_MATRIX_TEST_LED_FLAGS();
                RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
            if (!HAS_FLAGS(g_led_config.flags[i], 0x04)) {
                rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
            }
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool party_keylgihts(effect_params_t* params) {
    return party_effect_i(params, &party_math);
}

// LIGHTS PER LAYER
// Modded from the link below to match/use Matrix effects
// From https://www.reddit.com/r/olkb/comments/e0hurb/comment/fawrcem/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  // use the non noeeprom versions, to write these values to EEPROM too
  rgb_matrix_enable(); // Enable RGB by default
  rgb_matrix_sethsv(HSV_PURPLE);  // Set it to teal by default
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE); // set to breathing by default
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t rgbModelast = rgb_matrix_get_mode();
  HSV rgbHSVlast = rgb_matrix_get_hsv();
  switch(biton32(state)) {
  case 1:
    // tealish
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(rgbModelast);
    rgb_matrix_sethsv_noeeprom(rgbHSVlast.h+56,rgbHSVlast.s,rgbHSVlast.v);
    break;
  case 2:
    // greenish
    rgb_matrix_enable_noeeprom();	
    rgb_matrix_mode_noeeprom(rgbModelast);
    rgb_matrix_sethsv_noeeprom(rgbHSVlast.h+112,rgbHSVlast.s,rgbHSVlast.v);
    break;
  case 3:
    // orangeish
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(rgbHSVlast.h,rgbHSVlast.s,rgbHSVlast.v);
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_party_keylights);
    party_keylights(effect_params_t* params);
    break;
  default:
    // if not touched, purpleish
    //If enabled, set white
    if (rgb_matrix_is_enabled()) {
      rgb_matrix_sethsv_noeeprom(rgbHSVlast.h+168,rgbHSVlast.s,rgbHSVlast.v);
	  } else { //Otherwise go back to disabled
		  rgb_matrix_disable_noeeprom();
	  }
    break;
  }
  return state;
}
