# IoFreeIrp function

## Description

The **IoFreeIrp** routine releases a caller-allocated IRP from the caller's [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine.

## Parameters

### `Irp` [in]

Pointer to the IRP that is to be released.

## Remarks

This routine is the reciprocal to [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp) or [IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest). The released IRP must have been allocated by the caller.

This routine also releases an IRP allocated with [IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp) in which the caller set up its [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine that returns STATUS_MORE_PROCESSING_REQUIRED for the associated IRP.

**IoFreeIrp** does not free any MDLs that might be attached to the IRP. The driver that frees the IRP must explicitly free these MDLs. In addition, if the physical pages that are described by an MDL are locked, the driver must unlock the pages before it frees the MDL. However, the driver does not need to explicitly unmap these pages. Instead, [IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl) automatically unmaps the pages when it frees the MDL. For a code example that shows how to free an MDL chain, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine)

[IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)