# IOCTL_CAD_GET_CHARGING_STATUS_COMPLETE IOCTL

## Description

This IOCTL is for internal use only.

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

## See also

[**charging.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/charging/)