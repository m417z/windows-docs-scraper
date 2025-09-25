## Description

The *WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER* callback function initializes a driver's error source hardware and software state.

## Parameters

### `Context`

A pointer to the context that the driver supplied when it called [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver).

### `ErrorSourceId`

A ULONG value that uniquely identifies this driver as an error source.

## Return value

This function method returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A driver should store the error source identifier it receives as input to this callback function for later communication with WHEA. For example, if the driver detects an error condition, it calls [**WheaReportHwErrorDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheareporthwerrordevicedriver), providing the error data and the driver's ErrorSourceId, to report the error to WHEA. When a driver is stopped (for example to be updated), it calls [**WheaRemoveErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-whearemoveerrorsourcedevicedriver) to unregister its error source identifier.

Register your implementation of this callback function by setting the appropriate member of [**WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_error_source_configuration_device_driver) and then calling [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver).

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also

[*WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_uninitialize_device_driver)