# IoCsqRemoveNextIrp function

## Description

The **IoCsqRemoveNextIrp** routine removes the next matching IRP in the queue.

## Parameters

### `Csq` [in, out]

Pointer to the driver's dispatch table for cancel-safe IRP queues. The dispatch table must be initialized by [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize).

### `PeekContext` [in, optional]

A pointer to a driver-defined context value. **IoCsqRemoveNextIrp** passes this parameter to the driver's [CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp) routine. For more information, see the following Remarks section.

## Return value

This routine returns a pointer to the next matching IRP in the queue, or **NULL** if no more IRPs are available. The routine only returns IRPs that have not yet been canceled.

## Remarks

**IoCsqRemoveNextIrp** uses the queue's dispatch routines to remove the IRP. The **IoCsqRemoveNextIrp** routine:

1. Calls the queue's [CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock) routine to lock the queue.
2. Calls the queue's [CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp) routine to find the next matching IRP in the queue. **IoCsqRemoveNextIrp** passes the value of the *PeekContext* parameter as the *PeekContext* parameter of *CsqPeekNextIrp*. *CsqPeekNextIrp* returns a pointer to the next matching IRP, or **NULL** if there is no matching IRP.
3. If the return value of *CsqPeekNextIrp* is non-**NULL**, **IoCsqRemoveNextIrp** calls the queue's [CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp) routine to remove the IRP.
4. Calls the queue's [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) routine to unlock the queue.

For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

Note that **IoCsq*Xxx*** routines use the **DriverContext**[3] member of the IRP to hold IRP context information. Drivers that use these routines to queue IRPs must leave that member unused.

Callers of **IoCsqRemoveNextIrp** must be running at an IRQL <= DISPATCH_LEVEL. The driver's callback routines must work correctly at that IRQL.

## See also

[CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock)

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

[CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp)

[CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex)

[CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp)

[CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock)

[CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp)

[IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize)

[IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex)

[IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp)

[IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)