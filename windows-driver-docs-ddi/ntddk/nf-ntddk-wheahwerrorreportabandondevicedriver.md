## Description

This routine abandons the in progress error report and releases its resources.

## Parameters

### `ErrorHandle`

The handle returned by [**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver).

## Return value

Returns STATUS_SUCCESS or STATUS_INVALID_HANDLE if the handle is invalid.

## Remarks

If [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver) fails, or the error is no longer valid, the driver can call this routine to clean up resources without submitting a report to WHEA.

## See also