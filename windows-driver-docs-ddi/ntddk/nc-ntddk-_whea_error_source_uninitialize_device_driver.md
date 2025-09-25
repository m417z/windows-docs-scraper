## Description

The *WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER* callback function uninitializes a driver's error source hardware and software state.

## Parameters

### `Context`

A pointer to the context that the driver supplied when it called [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver).

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_error_source_configuration_device_driver) and then calling [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver).

## See also

[*WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_initialize_device_driver)