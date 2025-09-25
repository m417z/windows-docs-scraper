# KoDeviceInitialize function

## Description

*This function is intended for internal use only.*

The **KoDeviceInitialize** function adds a kernel COM create-item entry to the specified device object.

## Parameters

### `DeviceObject` [in]

Pointer to a device object. The device object is assumed to contain a KSOBJECT_HEADER in its device extension.

## Return value

Returns STATUS_SUCCESS if successful. Otherwise, it returns a memory allocation error.