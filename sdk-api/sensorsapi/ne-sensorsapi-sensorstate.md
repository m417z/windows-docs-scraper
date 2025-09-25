# SensorState enumeration

## Description

Defines possible operational states for sensors.

## Constants

### `SENSOR_STATE_MIN:0`

Minimum enumerated sensor state. Use **SENSOR_STATE_READY** instead.

### `SENSOR_STATE_READY`

Ready to send sensor data.

### `SENSOR_STATE_NOT_AVAILABLE`

The sensor is not available for use.

### `SENSOR_STATE_NO_DATA`

The sensor is available but does not have data.

### `SENSOR_STATE_INITIALIZING`

The sensor is available, but performing initialization. Try again later.

### `SENSOR_STATE_ACCESS_DENIED`

The sensor is available, but the user account does not have permission to access the sensor data. For more information about permissions, see [Managing User Permissions](https://learn.microsoft.com/windows/desktop/SensorsAPI/managing-user-permissions).

### `SENSOR_STATE_ERROR`

The sensor has raised an error.

### `SENSOR_STATE_MAX`

Maximum enumerated sensor state. Not a valid value.