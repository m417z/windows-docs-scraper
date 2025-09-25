# SensorsCxDeviceInitialize function

## Description

This function initializes the sensor in the class extension.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorConfig` [in]

A list of functions that the driver implements. For more information, see [SENSOR_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_controller_config).

## Return value

This function returns STATUS_SUCCESS when completed successfully. When an invalid parameter is supplied or this function fails, STATUS_INVALID_PARAMETER is returned. Other NTSTATUS values can also be returned.

## See also

[SENSOR_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_controller_config)