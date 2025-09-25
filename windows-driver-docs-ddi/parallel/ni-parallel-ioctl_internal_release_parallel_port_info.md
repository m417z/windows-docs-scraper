# IOCTL_INTERNAL_RELEASE_PARALLEL_PORT_INFO IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_RELEASE_PARALLEL_PORT_INFO** request returns STATUS_SUCCESS.

**Note** The intended purpose of this IOCTL is to make it possible to page the callback routines supported by the system-supplied function driver for parallel ports. However, this capability is not yet implemented.

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

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info)

[IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info)