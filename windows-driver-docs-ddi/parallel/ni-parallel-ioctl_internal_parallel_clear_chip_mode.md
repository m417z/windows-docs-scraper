# IOCTL_INTERNAL_PARALLEL_CLEAR_CHIP_MODE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARALLEL_CLEAR_CHIP_MODE** request clears the operating mode of a parallel port.

For more information see, [Setting and Clearing the Communication Mode on a ParallelPort](https://learn.microsoft.com/previous-versions/ff544801(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARALLEL_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_chip_mode) structure that the client allocates to input chip mode information. The client sets the **ModeFlags** member to the current operating mode.

### Input buffer length

The request sets the **Parameters.DeviceIoControl.InputBufferLength** member to the size, in bytes, of a PARALLEL_CHIP_MODE structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel ports or to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The value of the **Parameters.DeviceIoControl.InputBufferLength** member is less than the size, in bytes, of a PARALLEL_CHIP_MODE structure.

**STATUS_INVALID_DEVICE_STATE**

The specified operating mode is not the same as the current operating mode of the parallel port.

## See also

[PARALLEL_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_chip_mode)

[IOCTL_INTERNAL_PARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_set_chip_mode)