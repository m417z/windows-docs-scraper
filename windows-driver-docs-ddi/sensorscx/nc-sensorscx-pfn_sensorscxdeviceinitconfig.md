# *PFN_SENSORSCXDEVICEINITCONFIG callback function

## Description

Configures the sensor device.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `pFxDeviceInit`

A reference to WDFDEVICE_INIT.

### `pFdoAttributes`

A reference to WDF_OBJECT_ATTRIBUTES.

### `Flags`

The flags for the sensor driver. Reserved set to 0.

## Return value

This function returns STATUS_SUCCESS when completed successfully. When an invalid parameter is supplied or this function fails, STATUS_INVALID_PARAMETER is returned. This function can also return other NTSTATUS values.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXDEVICEINITCONFIG *PfnSensorscxdeviceinitconfig;

// Definition

NTSTATUS *PfnSensorscxdeviceinitconfig
(
	PSENSORSCX_DRIVER_GLOBALS DriverGlobals
	PWDFDEVICE_INIT pFxDeviceInit
	PWDF_OBJECT_ATTRIBUTES pFdoAttributes
	ULONG Flags
)
{...}

```