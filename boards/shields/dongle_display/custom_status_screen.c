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
    lv_obj_set_size(screen, 128, 32);  // Ensure screen size matches OLED

    // 🔹 Increase widget size to fill most of the height
    int widget_width = 60;  // Each widget takes ~half the screen width
    int widget_height = 28; // Almost full screen height

    // 🔹 Output Status Widget (Connection Type)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_set_size(zmk_widget_output_status_obj(&output_status_widget), widget_width, widget_height);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_LEFT_MID, 4, 0);  // Left side

    // 🔹 Battery Status Widget
    zmk_widget_dongle_battery_status_init(&dongle_battery_status_widget, screen);
    lv_obj_set_size(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), widget_width, widget_height);
    lv_obj_align(zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget), LV_ALIGN_RIGHT_MID, -4, 0);  // Right side

    return screen;
}
