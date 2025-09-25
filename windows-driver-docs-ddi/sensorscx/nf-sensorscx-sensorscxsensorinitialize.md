# SensorsCxSensorInitialize function

## Description

This function sets the enumeration properties of a sensor.

 For more information about sensor properties, see [Enumeration properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/enumeration-properties).

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pSensorConfig` [in]

A list of enumeration properties. For more information, see [SENSOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_config).

## Return value

This function returns NTSTATUS with different values. Some values that may be returned are the following:

* STATUS_SUCCESS is returned when the function completes successfully.
* STATUS_INVALID_PARAMETER is returned if any of the _In_ parameters are NULL or the **pSensorConfig->pEnumerationList->Count** variable is 0 or too big.
* STATUS_BUFFER_TOO_SMALL is returned if the **pSensorConfig** buffer is smaller than the size of the [SENSOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/ns-sensorscx-_sensor_config) structure.
* STATUS_NOT_FOUND is returned if there was an error constructing the controller object context from the **Sensor** object.