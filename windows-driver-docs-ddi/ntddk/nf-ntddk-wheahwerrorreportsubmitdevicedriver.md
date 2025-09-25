## Description

This routine submits an in progress error report to WHEA to be reported as a hardware error.

## Parameters

### `ErrorHandle`

The handle returned by [**WheaCreateHwErrorReportDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheacreatehwerrorreportdevicedriver).

## Return value

Returns STATUS_SUCCESS or one of the following:

* STATUS_INVALID_HANDLE: Invalid error handle
* STATUS_DEVICE_REMOVED: Error source has been removed
* STATUS_BUFFER_TOO_SMALL: Packet contains no sections
* STATUS_INSUFFICIENT_RESOURCES: Insufficient space for log data

Otherwise, this routine returns the status returned by [**WheaReportHwError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheareporthwerror).

## Remarks

Before calling this routine, the driver should add all desired sections by calling [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver).

After calling this routine, buffers in the buffer sets are no longer available for use, and the handle is invalid.

If an error has occurred, or the error is no longer valid, the driver can clean up without a report being submitted to WHEA by calling [**WheaHwErrorReportAbandonDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheahwerrorreportabandondevicedriver).

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also