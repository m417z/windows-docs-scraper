# IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS IOCTL

## Description

This IOCTL is not handled by video miniport drivers. It is handled entirely by the system-supplied video port driver.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

**Note** This IOCTL is obsolete in Windows Vista. Instead, use the Windows Management Instrumentation (WMI) **WmiMonitorBrightnessMethods** class. For information about WMI, see the documentation in the Microsoft Windows SDK.