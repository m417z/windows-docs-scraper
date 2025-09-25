# IOCTL_USB_DIAGNOSTIC_MODE_OFF IOCTL

## Description

The **IOCTL_USB_DIAGNOSTIC_MODE_OFF** I/O control has been deprecated. Do not use.

## Parameters

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