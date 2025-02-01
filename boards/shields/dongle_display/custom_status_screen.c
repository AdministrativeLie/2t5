/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "custom_status_screen.h"
#include "widgets/battery_status.h"
#include "widgets/output_status.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static struct zmk_widget_output_status output_status_widget;
static struct zmk_widget_dongle_battery_status dongle_battery_status_widget;

lv_style_t global_style;
lv_style_t text_style; // New style for larger text

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL);

    // Initialize global text style
    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, &lv_font_montserrat_16); // Larger Font
    lv_style_set_text_letter_space(&global_style, 1);
    lv_style_set_text_line_space(&global_style, 1);
    lv_obj_add_style(screen, &global_style, LV_PART_MAIN);

    // Initialize widget-specific text style
    lv_style_init(&text_style);
    lv_style_set_text_font(&text_style, &lv_font_montserrat_20); // Even larger for readability

    // Output Status Widget (Connection Type)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_add_style(zmk_widget_output_status_obj(&output_status_widget), &text_style, LV_PART_MAIN);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_TOP_MID, 0, 0); 

    // Battery Status Widget
    zmk_widget_dongle_battery_status_init(&dongle_battery_status_widget, screen);
    lv_obj_add_style(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), &text_style, LV_PART_MAIN);
    lv_obj_align(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), LV_ALIGN_BOTTOM_MID, 0, 0);

    return screen;
}
