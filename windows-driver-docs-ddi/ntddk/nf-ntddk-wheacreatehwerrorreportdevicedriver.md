## Description

This routine initializes an error report.

## Parameters

### `ErrorSourceId`

A ULONG that specifies the error source for which the packet is to be created. This is provided by WHEA to the driver's [*WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_initialize_device_driver) event callback function.

### `DeviceObject`

Pointer to a DEVICE_OBJECT corresponding to the driver, or NULL.

## Return value

This function returns a handle to the in progress error, or WHEA_ERROR_HANDLE_INVALID if the error report generation fails.

## Remarks

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also

[**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver)