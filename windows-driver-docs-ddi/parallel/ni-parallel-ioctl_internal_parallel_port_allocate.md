# IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE** request allocates a parallel port for exclusive access by a client. Before accessing port hardware, a client must first allocate it.

For more information, see [Synchronizing the Use of a ParallelPort](https://learn.microsoft.com/previous-versions/ff544809(v=vs.85)).

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

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel ports.

## See also

[IOCTL_INTERNAL_PARALLEL_PORT_FREE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_free)