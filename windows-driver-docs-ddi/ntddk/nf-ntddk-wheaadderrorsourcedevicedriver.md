# WheaAddErrorSourceDeviceDriver function

## Description

A device driver calls **WheaAddErrorSourceDeviceDriver** to add an error source.

## Parameters

### `Context`

An optional pointer to a caller-allocated context. WHEA provides the context as a parameter to driver-supplied callback routines. Can be NULL.

### `Configuration`

Pointer to a structure of type [**WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_error_source_configuration_device_driver) that contains a set of driver-supplied callback routines.

### `NumberPreallocatedErrorReports`

A value of type ULONG that specifies the number of records to preallocate. See Remarks for more information.

## Return value

This function method returns STATUS_SUCCESS if the error source is added. Otherwise it can return one of the following:

* STATUS_INVALID_PARAMETER: The configuration is missing initialize and/or uninitialize callback pointers.
* STATUS_INVALID_PARAMETER_2: A configuration with an invalid version was submitted.
* STATUS_INSUFFICIENT_RESOURCES: WHEA was unable to allocate space for the error source and its records.

## Remarks

To remove an error source, the driver calls [**WheaRemoveErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-whearemoveerrorsourcedevicedriver).

WHEA can preallocate memory for errors that will be reported at high IRQL (i.e. in the context of a device interrupt). For error sources reported at PASSIVE_LEVEL, preallocation is not required but if the device driver reports errors for its error source at DISPATCH_LEVEL or higher, error records must be preallocated.

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also

[**WheaRemoveErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-whearemoveerrorsourcedevicedriver)

[**WheaReportHwErrorDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheareporthwerrordevicedriver)

[**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver)