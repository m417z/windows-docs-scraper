# IOCTL_INTERNAL_SELECT_DEVICE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_SELECT_DEVICE** request:

* Allocates the parallel port

  The system-supplied function driver for parallel ports allocates the parallel port if the client does not set the PAR_HAVE_PORT_KEEP_PORT flag in the **CommandFlags** member of the input PARALLEL_1284_COMMAND structure. Otherwise, the parallel port function driver does not allocate the parallel port.
* Selects an IEEE 1284.3 daisy chain parallel device or an end-of-chain device attached to the parallel port

  Although a client can select an end-of-chain device using a select device request, Microsoft recommends using an [IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_allocate) request instead. The parallel port function driver selects the end-of-chain device before it allocates the parallel port to a client.

For more information, see [Selecting and Deselecting an IEEE 1284 Device Attached to a ParallelPort](https://learn.microsoft.com/previous-versions/ff544793(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** points to a [PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command) structure that the client allocates to input the select device information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member specifies the size, in bytes, of a PARALLEL_1284_COMMAND structure.

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

The specified device is not flagged internally as an end-of-chain device and the value of the **ID** member of the input structure is greater than the number of existing daisy chain devices.

## See also

[PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command)

[IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device)