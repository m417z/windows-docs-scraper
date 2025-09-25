# *PFN_SENSORSCXDEVICEINITIALIZE callback function

## Description

Initializes the sensor in the class extension.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `FxDevice`

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorConfig`

A list of functions that the driver implements.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXDEVICEINITIALIZE *PfnSensorscxdeviceinitialize;

// Definition

NTSTATUS *PfnSensorscxdeviceinitialize
(
	PSENSORSCX_DRIVER_GLOBALS DriverGlobals
	WDFDEVICE FxDevice
	PSENSOR_CONTROLLER_CONFIG pSensorConfig
)
{...}

```