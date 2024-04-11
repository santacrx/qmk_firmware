// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(party_keylights)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV party_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].x - time;
    return hsv;
}

static uint8_t current_layer = get_highest_layer(layer_state);

static bool party_keylights(effect_params_t* params, current_layer) {
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    uint8_t layer = current_layer;

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t i = g_led_config.matrix_co[row][col];

                if (i >= led_min && i < led_max && i != NO_LED && HAS_FLAGS(g_led_config.flags[i], 0x04) &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    RGB rgb = rgb_matrix_hsv_to_rgb(party_math(rgb_matrix_config.hsv, i, time));
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
                if (!HAS_FLAGS(g_led_config.flags[i], 0x04)) {
                    rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
                }
            }
        }
    return rgb_matrix_check_finished_leds(led_max);

}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
