/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright (C) 2015 Motorola Mobility LLC
 */

#include <hardware/sensors.h>
#include <hardware/mot_sensorhub_stml0xx.h>

#include "Sensors.h"

static const struct sensor_t sSensorList[] = {
	{ "3-axis Accelerometer",
		"Kionix",
		1,
		SENSORS_HANDLE_BASE + ID_A,
		SENSOR_TYPE_ACCELEROMETER,
		RANGE_G * GRAVITY_EARTH,
		GRAVITY_EARTH / LSG,
		0.25f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
#ifdef _ENABLE_MAGNETOMETER
	{ "3-axis Calibrated Magnetic field sensor",
		"Asahi Kasei Microdevices",
		1,
		SENSORS_HANDLE_BASE + ID_M,
		SENSOR_TYPE_MAGNETIC_FIELD,
		4912.0f,
		CONVERT_M,
		0.10f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
	{ "3-axis Uncalibrated Magnetic field sensor",
		"Asahi Kasei Microdevices",
		1,
		SENSORS_HANDLE_BASE + ID_UM,
		SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED,
		4912.0f,
		CONVERT_M,
		0.10f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
	{ "Orientation sensor",
		"Asahi Kasei Microdevices",
		1,
		SENSORS_HANDLE_BASE + ID_OR,
		SENSOR_TYPE_ORIENTATION,
		360.0f,
		CONVERT_OR,
		0.425f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
/* Don't expose rotation vector
	{ "Rotation Vector sensor",
		"Asahi Kasei Microdevices",
		1,
		SENSORS_HANDLE_BASE + ID_RV,
		SENSOR_TYPE_ROTATION_VECTOR,
		1,
		CONVERT_RV,
		0.425f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
*/
#endif /* _ENABLE_MAGNETOMETER */
	{ "Ambient Light sensor",
		"TAOS",
		1,
		SENSORS_HANDLE_BASE + ID_L,
		SENSOR_TYPE_LIGHT,
		27000.0f,
		1.0f,
		0.175f,
		0,
		0,
		0,
		"",
                "",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE,
		{} },
	{ "Proximity sensor",
		"TAOS",
		1,
		SENSORS_HANDLE_BASE + ID_P,
		SENSOR_TYPE_PROXIMITY,
		100.0f,
		100.0f,
		3.0f,
		0,
		0,
		0,
		"",
                "",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
	{ "Display Rotation sensor",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_DR,
		SENSOR_TYPE_DISPLAY_ROTATE,
		4.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.display_rotate",
		"",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE,
		{} },
	{ "Flat Up",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_FU,
		SENSOR_TYPE_FLAT_UP,
		1.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.flat_up",
		"",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
	{ "Flat Down",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_FD,
		SENSOR_TYPE_FLAT_DOWN,
		1.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.flat_down",
		"",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
	{ "Stowed",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_S,
		SENSOR_TYPE_STOWED,
		1.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.stowed",
		"",
		0,
		SENSOR_FLAG_ON_CHANGE_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
	{ "Camera Activation sensor",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_CA,
		SENSOR_TYPE_CAMERA_ACTIVATE,
		1.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.camera_activate",
		"",
		0,
		SENSOR_FLAG_SPECIAL_REPORTING_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
#ifdef _ENABLE_LIFT
	{ "Lift Gesture Virtual Sensor",
		"Motorola",
		1,
		SENSORS_HANDLE_BASE + ID_LF,
		SENSOR_TYPE_LIFT_GESTURE,
		1.0f,
		1.0f,
		0.0f,
		0,
		0,
		0,
		"com.motorola.sensor.lift",
		"",
		0,
		SENSOR_FLAG_SPECIAL_REPORTING_MODE | SENSOR_FLAG_WAKE_UP,
		{} },
#endif
#ifdef _ENABLE_ACCEL_SECONDARY
	{ "3-axis Accelerometer, Secondary",
		"Kionix",
		1,
		SENSORS_HANDLE_BASE + ID_A2,
		SENSOR_TYPE_ACCELEROMETER,
		RANGE_G * GRAVITY_EARTH,
		GRAVITY_EARTH / LSG,
		0.25f,
		10000,
		0,
		0,
		"",
		"",
		200000,
		SENSOR_FLAG_CONTINUOUS_MODE,
		{} },
#endif
};
