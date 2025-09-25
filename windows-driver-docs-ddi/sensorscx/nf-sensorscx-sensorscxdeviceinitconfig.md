# SensorsCxDeviceInitConfig function

## Description

This function configures the sensor device.

## Parameters

### `pFxDeviceInit` [in, out]

A reference to WDFDEVICE_INIT.

### `pFdoAttributes` [in, out]

A reference to WDF_OBJECT_ATTRIBUTES.

### `Flags` [in]

The flags for the sensor driver. Reserved set to 0.

## Return value

This function returns STATUS_SUCCESS when completed successfully. When an invalid parameter is supplied or this function fails, STATUS_INVALID_PARAMETER is returned. This function can also return other NTSTATUS values.