# WheaReportHwErrorDeviceDriver function

## Description

To report a hardware error, the driver calls the **WheaReportHwErrorDeviceDriver** function.

## Parameters

### `ErrorSourceId`

The error source ID WHEA provided when it called the [*_WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_initialize_device_driver) callback.

### `DeviceObject`

A pointer to the device object associated with the error condition.

### `ErrorData`

The buffer containing the driver's hardware error data. This information is hardware-specific, and must not exceed the *MaxRawDataLength* that the driver provided to [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver)
.

### `ErrorDataLength`

A value of type ULONG specifying the size, in bytes, of the error data.

### `SectionTypeGuid`

Specifies what type of error data is being reported. This may be, but is not required to be, one of the GUIDs defined in the Appendix N of the [UEFI Specification](https://uefi.org/sites/default/files/resources/UEFI%20Spec%202_6.pdf), in which case the error information matches one of the specified section types. The caller can also create a GUID and private section format.

### `ErrorSeverity`

An enumeration value of type [**WHEA_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity) specifying the severity of the error condition.

### `DeviceFriendlyName`

An optional string up to 20 bytes in length (including NULL terminator) that describes the device associated with the error condition. This information is copied into the resulting WHEA error record and is informational only. The intent is to place this information in the error record so when event logs are created a consumer can easily troubleshoot device problems.

## Return value

This function method returns STATUS_SUCCESS or an appropriate error code.

## Remarks

## See also

[**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver)

[**WheaRemoveErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-whearemoveerrorsourcedevicedriver)