# IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT** request disconnects an interrupt service routine (and an optional deferred port check service routine) that was connected by using an [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt) request. Only kernel-mode drivers can connect and disconnect an interrupt routine.

**Note** Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the connect interrupt request is disabled. For more information, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARALLEL_INTERRUPT_SERVICE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_service_routine) structure that the client allocates for the input of interrupt service information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a PARALLEL_INTERRUPT_SERVICE_ROUTINE structure.

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

The value of the **Parameters.DeviceIoControl.InputBufferLength** member is less than the size, in bytes, of a PARALLEL_INTERRUPT_SERVICE_ROUTINE structure.

**STATUS_INVALID_PARAMETER**

The specified interrupt service routine is not connected.

## See also

[PARALLEL_INTERRUPT_SERVICE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_service_routine)

[IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt)

[PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information)