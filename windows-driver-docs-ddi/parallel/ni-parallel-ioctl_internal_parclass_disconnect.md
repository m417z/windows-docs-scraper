# IOCTL_INTERNAL_PARCLASS_DISCONNECT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARCLASS_DISCONNECT** request disconnects a client from a parallel device. After disconnecting from a parallel device, a client must not use any information obtained from a previous [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request.

For more information, see [Connecting to a Parallel Device](https://learn.microsoft.com/previous-versions/ff543942(v=vs.85)).

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

[IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect)