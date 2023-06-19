/* Copyright 2022 Sadek Baroudi
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
 */

#pragma once
#include QMK_KEYBOARD_H
#include "keyboards/fingerpunch/src/fp.h"

layer_state_t fp_layer_state_set_pointing(layer_state_t state);
bool fp_process_record_pointing(uint16_t keycode, keyrecord_t *record);
void fp_pointing_device_set_cpi_combined_defaults(void);
void fp_scroll_layer_set(bool scroll_value);
void fp_scroll_keycode_set(bool scroll_value);
bool fp_scroll_get(void);
void fp_scroll_keycode_toggle(void);
void fp_scroll_apply_dpi(void);
void fp_snipe_layer_set(bool snipe_value);
void fp_snipe_keycode_set(bool snipe_value);
bool fp_snipe_get(void);
void fp_snipe_keycode_toggle(void);
void fp_snipe_apply_dpi(void);
void fp_zoom_layer_set(bool zoom_value);
void fp_zoom_keycode_set(bool zoom_value);
void fp_zoom_keycode_toggle(void);
bool fp_zoom_get(void);
uint32_t fp_zoom_unset_hold(uint32_t triger_time, void *cb_arg);

#ifdef POINTING_DEVICE_ENABLE
// Add MOUSE_EXTENDED_REPORT by default
#    ifndef FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE
#        define MOUSE_EXTENDED_REPORT
#    endif

#    ifndef FP_POINTING_DEFAULT_DPI
#        define FP_POINTING_DEFAULT_DPI 1000
#    endif

#    ifndef FP_POINTING_SNIPING_DPI
#        define FP_POINTING_SNIPING_DPI 50
#    endif

#    ifndef FP_POINTING_SNIPING_LAYER
#        define FP_POINTING_SNIPING_LAYER 2
#    endif

#    ifndef FP_POINTING_SCROLLING_DPI
#        define FP_POINTING_SCROLLING_DPI 10
#    endif

#    ifndef FP_POINTING_SCROLLING_LAYER
#        define FP_POINTING_SCROLLING_LAYER 3
#    endif

#    ifndef FP_POINTING_COMBINED_SCROLLING_LEFT
#        define FP_POINTING_COMBINED_SCROLLING_LEFT true
#    endif

#    ifndef FP_POINTING_COMBINED_SCROLLING_RIGHT
#        define FP_POINTING_COMBINED_SCROLLING_RIGHT false
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY 3
#    endif

#    ifndef FP_POINTING_ZOOMING_LAYER
#        define FP_POINTING_ZOOMING_LAYER 1
#    endif

#endif
