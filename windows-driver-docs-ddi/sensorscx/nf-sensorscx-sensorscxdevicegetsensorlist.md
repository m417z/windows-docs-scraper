# SensorsCxDeviceGetSensorList function

## Description

This function returns a list of sensor instances associated with a WDFDEVICE.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorList` [out]

A list of sensor instances.

### `pListCount` [in, out]

The number of SENSOROBJECTS in pSensorInstanceList.

## Return value

This function returns NTSTATUS with different values. Some values that may be returned are the following:

* STATUS_SUCCESS is returned if the function completes successfully.
* STATUS_INVALID_PARAMETER is returned if any of the _In_ parameters are NULL.
* STATUS_NOT_FOUND is returned if the controller is not available from the **FxDevice**.