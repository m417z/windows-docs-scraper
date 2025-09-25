# IOCTL_PAR_QUERY_INFORMATION IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_QUERY_INFORMATION request returns the status of an IEEE 1284 end-of-chain device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a PAR_QUERY_INFORMATION structure that the client allocates to output status information. The system-supplied bus driver for parallel ports sets the **Status** member to a bitwise OR of one or more of the following operating conditions:

PARALLEL_BUSY

PARALLEL_NOT_CONNECTED

PARALLEL_OFF_LINE

PARALLEL_PAPER_EMPTY

PARALLEL_POWER_OFF

PARALLEL_SELECTED

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_query_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a PAR_QUERY_INFORMATION structure. Otherwise, the **Information** is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The value of the **Parameters.DeviceIoControl.OutputBufferLength** member is less than the size, in bytes, of a PAR_QUERY_INFORMATION structure.

## See also

[PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_query_information)

[IOCTL_PAR_QUERY_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_location)