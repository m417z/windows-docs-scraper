## Description

This routine sets the error severity of the packet and sections.

## Parameters

### `ErrorHandle`

The handle returned by [**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver).

### `ErrorSeverity`

An enumeration value from [**WHEA_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity) representing the new severity for the error.

## Return value

Returns STATUS_SUCCESS or STATUS_INVALID_HANDLE if the handle is invalid.

## Remarks

## See also