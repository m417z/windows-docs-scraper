## Description

The **IoSetCompletionRoutineEx** routine registers an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, which is called when the next-lower-level driver has completed the requested operation for the given IRP.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's device object.

### `Irp` [in]

Pointer to the [**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that the driver is processing.

### `CompletionRoutine` [in]

Specifies the entry point for the driver-supplied [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, which is called when the next-lower driver completes the packet.

### `Context` [in, optional]

Pointer to a driver-determined context to pass to the *IoCompletion* routine. Context information must be stored in nonpaged memory, because the *IoCompletion* routine is called at IRQL <= DISPATCH_LEVEL.

### `InvokeOnSuccess` [in]

Specifies whether the completion routine is called if the IRP is completed with a success status value in the IRP's [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure, based on results of the NT_SUCCESS macro (see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)).

### `InvokeOnError` [in]

Specifies whether the completion routine is called if the IRP is completed with a nonsuccess status value in the IRP's **IO_STATUS_BLOCK** structure.

### `InvokeOnCancel` [in]

Specifies whether the completion routine is called if a driver or the kernel has called [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp) to cancel the IRP.

## Return value

This routine returns STATUS_SUCCESS on success, or STATUS_INSUFFICIENT_RESOURCES if insufficient memory is available for the operation.

## Remarks

Unlike [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine), the **IoSetCompletionRoutineEx** routine returns an NTSTATUS value. The driver must check this value to determine if the [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine was successfully registered. If the *IoCompletion* routine is successfully registered, **IoSetCompletionRoutineEx** allocates memory that remains allocated until the *IoCompletion* routine executes. Drivers must ensure that their *IoCompletion* routine executes by calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver); otherwise, the kernel will leak memory.

The *IoCompletion* routine must belong to the driver that owns the device object pointed to by *DeviceObject*. This requirement prevents the *IoCompletion* routine from being unloaded before it returns.

The behavior of **IoSetCompletionRoutineEx** is the same as the [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) routine, except that:

- **IoSetCompletionRoutineEx** guarantees that a non-Plug and Play driver is not unloaded before the *IoCompletion* routine runs.

- **IoSetCompletionRoutineEx** is a routine that returns an NTSTATUS value.

## See also

[**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine)

[IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)