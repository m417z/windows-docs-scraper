## Description

To remove a previously added error source, a device driver calls **WheaRemoveErrorSourceDeviceDriver**.

## Parameters

### `ErrorSourceId`

The error source ID WHEA provided when it called the [*_WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_initialize_device_driver) callback.

## Return value

This function returns STATUS_SUCCESS or an error code.

STATUS_RESOURCE_IN_USE is returned if error handles are still in use.

## Remarks

This routine must be called at PASSIVE_LEVEL as it synchronously removes the device driver's error source.

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also

[**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver)