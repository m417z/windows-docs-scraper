# IOCTL_SERENUM_PORT_DESC IOCTL

## Description

The **IOCTL_SERENUM_PORT_DESC** request returns a description of the RS-232 port associated with a filter DO.

This request is not implemented and is **obsolete**. The request must not be used in any Microsoft Windows drivers.

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