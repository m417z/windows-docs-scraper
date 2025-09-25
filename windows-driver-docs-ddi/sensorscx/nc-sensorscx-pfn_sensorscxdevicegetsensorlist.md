# *PFN_SENSORSCXDEVICEGETSENSORLIST callback function

## Description

Returns a list of sensor instances associated with a WDFDEVICE.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `FxDevice`

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorList`

A list of sensor instances.

### `pListCount`

The number of SENSOROBJECTS in *pSensorList*.

## Return value

Returns NTSTATUS with different values. Some values that may be returned are the following:

* STATUS_SUCCESS is returned if the function completes successfully.
* STATUS_INVALID_PARAMETER is returned if any of the In parameters are NULL.
* STATUS_NOT_FOUND is returned if the controller is not available from the FxDevice.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXDEVICEGETSENSORLIST *PfnSensorscxdevicegetsensorlist;

// Definition

NTSTATUS *PfnSensorscxdevicegetsensorlist
(
	PSENSORSCX_DRIVER_GLOBALS DriverGlobals
	WDFDEVICE FxDevice
	SENSOROBJECT *pSensorList
	PULONG pListCount
)
{...}

```

## Remarks

## See also