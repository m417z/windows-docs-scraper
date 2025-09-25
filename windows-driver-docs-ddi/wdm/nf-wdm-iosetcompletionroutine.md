## Description

The **IoSetCompletionRoutine** routine registers an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, which will be called when the next-lower-level driver has completed the requested operation for the given IRP.

## Parameters

### `Irp` [in]

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that the driver is processing.

### `CompletionRoutine` [in, optional]

Specifies the entry point for the driver-supplied [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine, which is called when the next-lower driver completes the packet.

### `Context` [in, optional]

Pointer to a driver-determined context to pass to the [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine. Context information must be stored in nonpaged memory, because the *IoCompletion* routine is called at IRQL <= DISPATCH_LEVEL.

### `InvokeOnSuccess` [in]

Specifies whether the completion routine is called if the IRP is completed with a success status value in the IRP's [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure, based on results of the **NT_SUCCESS** macro (see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)).

### `InvokeOnError` [in]

Specifies whether the completion routine is called if the IRP is completed with a nonsuccess status value in the IRP's **IO_STATUS_BLOCK** structure.

### `InvokeOnCancel` [in]

Specifies whether the completion routine is called if a driver or the kernel has called [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp) to cancel the IRP.

## Remarks

Only a driver that can guarantee it will not be unloaded before its completion routine finishes can use **IoSetCompletionRoutine**. Otherwise, the driver must use [IoSetCompletionRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex), which prevents the driver from unloading until its completion routine executes.

This routine sets the transfer address of the [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine in the given IRP. The lowest-level driver in a chain of layered drivers cannot call this routine.

**IoSetCompletionRoutine** registers the specified routine to be called when the next-lower-level driver has completed the requested operation in any or all of the following ways:

- With a success status value

- With a nonsuccess status value

- By canceling the IRP

Usually, the I/O status block is set by the underlying device driver. It is read but not altered by any higher-level drivers' *IoCompletion* routines.

Higher-level drivers that allocate IRP's with [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp) or [IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest) must call this routine with all *InvokeOn*Xxx parameters set to **TRUE** before passing the driver-allocated IRP to [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver). When the *IoCompletion* routine is called with such an IRP, it must free the driver-allocated IRP and any other resources that the driver set up for the request, such as MDLs with [IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl). Such a driver should return STATUS_MORE_PROCESSING_REQUIRED when it calls [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp) to forestall the I/O manager's completion processing for the driver-allocated IRP.

Non-PnP drivers that might be unloaded before their *IoCompletion* routines run should use [IoSetCompletionRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex) instead.

## See also

[**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[IoSetCompletionRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex)