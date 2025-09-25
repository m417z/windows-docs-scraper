# IOCTL_PAR_IS_PORT_FREE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_IS_PORT_FREE request determines if a parallel device's parent parallel port is free at the time the system-supplied bus driver for parallel ports processes the request. This request is provided primarily for user-mode clients.

This request is processed immediately after the I/O manager calls the parallel port bus driver's dispatch routine for device control requests. Note, however, that the status of the parallel port can change between the time that the parallel port bus driver completes the request and the time that control returns to a user-mode client.

Kernel-mode clients can directly determine if a parallel port is free by calling the system-supplied [PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine) callback.

For more information, see [Locking and Unlocking a ParallelPort for Use by a Parallel Device](https://learn.microsoft.com/previous-versions/ff544195(v=vs.85)).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a BOOLEAN buffer that the client allocates to output the status of the parallel port. If the parallel port is free, the system-supplied function driver for parallel ports sets the buffer to **TRUE**, otherwise it sets the buffer to **FALSE**.

### Output buffer length

The length of a BOOLEAN.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a BOOLEAN.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member is less than the size, in bytes, of a BOOLEAN.

## See also

[IOCTL_INTERNAL_PARALLEL_PORT_FREE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_free)

[PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine)

[IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port)