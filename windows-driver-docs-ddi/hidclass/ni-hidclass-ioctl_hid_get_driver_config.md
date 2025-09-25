# IOCTL_HID_GET_DRIVER_CONFIG IOCTL

## Description

The **IOCTL_HID_GET_DRIVER_CONFIG**
request retrieves the driver configuration.

This IOCTL is reserved for system use.

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