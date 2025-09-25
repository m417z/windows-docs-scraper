# ACTIVITY_STATE enumeration

## Description

This enumeration represents the activity states reported by the activity detection sensor.

## Constants

### `ActivityState_Unknown`

The sensor cannot accurately determine the current activity.

### `ActivityState_Stationary`

Indicates that the sensor is currently stationary.

### `ActivityState_Fidgeting`

Describes the current activity as "fidgeting."

### `ActivityState_Walking`

Describes the current activity as "walking."

### `ActivityState_Running`

Describes the current activity as "running."

### `ActivityState_InVehicle`

Describes the current activity as "traveling in a vehicle."

### `ActivityState_Biking`

Describes the current activity as "biking."

### `ActivityState_Idle`

Describes the current activity as "idle."

### `ActivityState_Max`

Indicates that the current activity state is generating maximum sensor values. In this scenario the sensor doesn't indicate what the activity is.

### `ActivityState_Force_Dword`

Used to force the ACTIVITY_STATE enum to a 32-bit data type (a DWORD).

## Remarks

For more information about the sensor data fields that use this enumeration, see [Activity detection sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/activity-detection-sensor-data-fields).

## See also

[Activity detection sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/activity-detection-sensor-data-fields)