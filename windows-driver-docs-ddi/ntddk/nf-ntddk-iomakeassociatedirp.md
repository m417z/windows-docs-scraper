# IoMakeAssociatedIrp function

## Description

This routine is reserved for use by file systems and file system filter drivers. The **IoMakeAssociatedIrp** routine allocates and initializes an IRP to be associated with a master IRP sent to a highest-level driver, allowing the caller to split the original request and send associated IRPs on to lower-level drivers.

## Parameters

### `Irp` [in]

Pointer to the master IRP that was input to a highest-level driver's Dispatch routine.

### `StackSize` [in]

Specifies the number of stack locations to be allocated for the associated IRP. The value must be at least equal to the *StackSize* of the next-lower driver's device object, but the associated IRP can have an additional stack location for the caller.

## Return value

**IoMakeAssociatedIrp** returns a pointer to the associated IRP or returns a **NULL** pointer if an IRP cannot be allocated.

## Remarks

Only a highest-level driver can call this routine.

The I/O manager completes the master IRP automatically when lower drivers have completed all associated IRPs as long as the caller has not set its [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine in an associated IRP and returned STATUS_MORE_PROCESSING_REQUIRED from its *IoCompletion* routine. In these circumstances, the caller must explicitly complete the master IRP when that driver has determined that all associated IRPs were completed.

Only the master IRP is associated with a thread; associated IRPs are not. For this reason, the I/O manager cannot call [Cancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionrequest-cancel) routines for associated IRPs when a thread exits. When the master IRP's thread exits, the I/O manager calls the master IRP's *Cancel* routine. The *Cancel* routine is responsible for tracking down all associated IRPs and calling [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp) to cancel them.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)