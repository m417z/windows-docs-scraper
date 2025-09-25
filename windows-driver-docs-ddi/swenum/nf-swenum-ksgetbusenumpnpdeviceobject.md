# KsGetBusEnumPnpDeviceObject function

## Description

*This function is intended for internal use only.*

The **KsGetBusEnumPnpDeviceObject** function retrieves the Plug and Play device object attached to the given device object.

## Parameters

### `DeviceObject` [in]

Pointer to the device object from which to retrieve the Plug and Play device object.

### `PnpDeviceObject` [out]

Pointer to the device object to receive the Plug and Play device object pointer.

## Return value

Returns STATUS_SUCCESS if successful, or STATUS_INVALID_PARAMETER if *DeviceObject* does not contain a device extension, or if the device extension specified in *DeviceObject* is not that of an FDO.