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

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, 32, 128);  // Treat the screen as rotated

    // 🔹 Increase widget size to fill the rotated screen
    int widget_width = 28;   // Almost full height (since rotated)
    int widget_height = 60;  // Half the width of the rotated screen

    // 🔹 Output Status Widget (Connection Type)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_set_size(zmk_widget_output_status_obj(&output_status_widget), widget_width, widget_height);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_TOP_MID, 0, 4);  // Now at the "top" (side)

    // 🔹 Battery Status Widget
    zmk_widget_dongle_battery_status_init(&dongle_battery_status_widget, screen);
    lv_obj_set_size(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), widget_width, widget_height);
    lv_obj_align(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), LV_ALIGN_BOTTOM_MID, 0, -4);  // Now at the "bottom" (side)

    return screen;
}
