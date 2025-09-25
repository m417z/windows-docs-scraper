# IOCTL_INTERNAL_PARCLASS_CONNECT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARCLASS_CONNECT** request returns information about a parallel port and the callback routines that the system-supplied bus driver for parallel ports provides to operate the parallel port.

For more information, see [Connecting to a Parallel Device](https://learn.microsoft.com/previous-versions/ff543942(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure.

### Input buffer length

The value of the **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure that the client allocates to output information.

### Output buffer length

The size of a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a PARCLASS_INFORMATION structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The value of the **Parameters.DeviceIoControl.OutputBufferLength** member is less than the size, in bytes, of a PARCLASS_INFORMATION structure.

## See also

[PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information)

[IOCTL_INTERNAL_PARCLASS_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_disconnect)