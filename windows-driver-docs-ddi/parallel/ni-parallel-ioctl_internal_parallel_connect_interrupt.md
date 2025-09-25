# IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT** request connects an optional interrupt service routine and an optional *deferred port check* routine to a parallel port. Only kernel-mode drivers can use this request.

The connect interrupt request returns information that the driver can use in the context of a driver-specific ISR. The information includes a pointer to the interrupt object and pointers to callback routines that allocate and free the parallel port at IRQL = DIRQL.

**Note** Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the connect interrupt request is disabled. For more information, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARALLEL_INTERRUPT_SERVICE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_service_routine) structure that the client allocates to input interrupt service information. The system-supplied function driver for parallel ports uses the same memory buffer, but casts it to a different data type to output information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a PARALLEL_INTERRUPT_SERVICE_ROUTINE structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a PARALLEL_INTERRUPT_INFORMATION structure that the parallel port function driver uses to output parallel interrupt information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a [PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information) structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel ports or to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

At least one of the following is true:

The value of the **Parameters.DeviceIoControl.InputBufferLength** member is less than the size, in bytes, of a PARALLEL_INTERRUPT_SERVICE_ROUTINE structure.

The value of the **Parameters.DeviceIoControl.OuputBufferLength** member is less than the size, in bytes, of a PARALLEL_INTERRUPT_INFORMATION structure.

## See also

[PARALLEL_INTERRUPT_SERVICE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_service_routine)

[IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_disconnect_interrupt)

[PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information)