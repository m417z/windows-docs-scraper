# IOCTL_INTERNAL_DESELECT_DEVICE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_DESELECT_DEVICE** request deselects an IEEE 1284.3 daisy-chain device or an IEEE 1284 end-of-chain device attached to a parallel port.

For more information, see [Selecting and Deselecting an IEEE 1284 Device Attached to a ParallelPort](https://learn.microsoft.com/previous-versions/ff544793(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command) structure that the client allocates to input IEEE 1284.3 command information. The client can free the parallel port by not setting the PAR_HAVE_PORT_KEEP_PORT flag in the **CommandFlags** member.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member specifies the size, in bytes, of the PARALLEL_1284_COMMAND structure.

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

The value of the **Parameters.DeviceIoControl.InputBufferLength** member is less than the size, in bytes, of a PARALLEL_1284_COMMAND structure.

**STATUS_INVALID_PARAMETER**

The specified device is not flagged internally as an end-of-chain device, and the specified ID value is greater than the number of existing daisy-chain devices.

## See also

[PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command)

[IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device)