## Description

This routine adds a new section to an error report, and hands the caller a buffer set that can be populated with information.

## Parameters

### `ErrorHandle`

A WHEA_ERROR_HANDLE obtained from [**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver) that specifies the packet that is being operated on.

### `SectionDataLength`

A ULONG that specifies the length, in bytes, of the data to be added to the section.

### `BufferSet`

A pointer to a [**WHEA_DRIVER_BUFFER_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_driver_buffer_set) structure that will be populated with a set of buffers for the user to interact with.

## Return value

Returns STATUS_SUCCESS or one of the following:

* STATUS_INVALID_HANDLE: The ErrorHandle is invalid.
* STATUS_DEVICE_REMOVED: The error source has been removed.
* STATUS_INSUFFICIENT_RESOURCES: There is not enough space for the data.

## Remarks

This routine can be called up to **MaxSectionsPerReport** times as specified in the [**WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_error_source_configuration_device_driver) structure supplied to [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver).

Also see [**WheaHwErrorReportSetSectionNameDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheahwerrorreportsetsectionnamedevicedriver), which is a helper function for updating the FRUText.

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also

[**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver)