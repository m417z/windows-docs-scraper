# IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO** request returns Plug and Play information about a parallel port.

For more information, see [Obtaining Information About a ParallelPort](https://learn.microsoft.com/previous-versions/ff544223(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A [PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information) structure.

### Input buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information) structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a PARALLEL_PNP_INFORMATION structure that the client allocates to output Plug and Play information.

### Output buffer length

The size of a PARALLEL_PNP_INFORMATION structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel ports or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The value of **Parameters.DeviceIoControl.OutputBufferLength** is less than the size, in bytes, of a PARALLEL_PNP_INFORMATION structure.

## See also

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)