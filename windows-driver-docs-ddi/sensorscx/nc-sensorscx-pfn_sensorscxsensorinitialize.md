# *PFN_SENSORSCXSENSORINITIALIZE callback function

## Description

Sets the enumeration properties of a sensor.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `Sensor`

A reference to a sensor object.

### `pSensorConfig`

A list of functions that the driver implements.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXSENSORINITIALIZE *PfnSensorscxsensorinitialize;

// Definition

NTSTATUS *PfnSensorscxsensorinitialize
(
	PSENSORSCX_DRIVER_GLOBALS DriverGlobals
	SENSOROBJECT Sensor
	PSENSOR_CONFIG pSensorConfig
)
{...}

```