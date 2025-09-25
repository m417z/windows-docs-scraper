# IOCTL_INTERNAL_UNLOCK_PORT_NO_DESELECT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_UNLOCK_PORT_NO_DESELECT** request frees a parallel device's parent parallel port. The request does not deselect the parallel device on the parallel port.

This request is only supported in Windows XP and later.

For more information, see [Locking and Unlocking a ParallelPort for Use by a Parallel Device](https://learn.microsoft.com/previous-versions/ff544195(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel devices.

## See also

[IOCTL_INTERNAL_UNLOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_unlock_port)

[IOCTL_INTERNAL_LOCK_PORT_NO_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port_no_select)

[IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port)