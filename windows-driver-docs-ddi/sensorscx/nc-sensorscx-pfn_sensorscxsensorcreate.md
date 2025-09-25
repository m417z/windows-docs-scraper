# *PFN_SENSORSCXSENSORCREATE callback function

## Description

Creates an instance of a sensor in the class extension.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `FxDevice`

A WDFDEVICE handle to the framework device object that represents the sensor.

### `pSensorAttributes`

A reference to sensor attributes, in WDF_OBJECT_ATTRIBUTES.

### `pSensor`

A reference to a sensor object.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXSENSORCREATE *PfnSensorscxsensorcreate;

// Definition

NTSTATUS *PfnSensorscxsensorcreate
(
	PSENSORSCX_DRIVER_GLOBALS DriverGlobals
	WDFDEVICE FxDevice
	PWDF_OBJECT_ATTRIBUTES pSensorAttributes
	PSENSOROBJECT pSensor
)
{...}

```