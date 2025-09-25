# IoCsqInsertIrp function

## Description

The **IoCsqInsertIrp** routine inserts an IRP in the driver's cancel-safe IRP queue.

## Parameters

### `Csq` [in, out]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the driver's cancel-safe IRP queue. This structure must have been initialized by [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize) or [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex).

### `Irp` [in, out]

Pointer to the IRP to be queued.

### `Context` [out, optional]

Pointer to an [IO_CSQ_IRP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. **IoCsqInsertIrp** initializes this structure with context information for the inserted IRP. The driver passes this value to [IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp) to delete the IRP from the queue. *Context* can be **NULL** if the driver will not use **IoCsqRemoveIrp** to remove this IRP from the queue.

## Remarks

**IoCsqInsertIrp** uses the queue's dispatch routines to insert the IRP. The **IoCsqInsertIrp** routine:

1. Calls the queue's [CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock) routine to lock the queue.
2. Calls the queue's [CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp) routine to insert the IRP.
3. Marks the IRP as pending.
4. Calls the queue's [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) routine to unlock the queue.

If the IRP to be inserted has already been canceled, **IoCsqInsertIrp** does not attempt to insert the IRP into the queue.

Drivers can also use [IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex) to insert an IRP into the queue. For a queue that is specified by [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex), **IoCsqInsertIrpEx** provides additional capabilities. For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

Note that the **IoCsq*Xxx*** routines use the **DriverContext**[3] member of the IRP to hold IRP context information. Drivers that use these routines to queue IRPs must leave that member unused.

Callers of **IoCsqInsertIrp** must be running at an IRQL <= DISPATCH_LEVEL. The driver's callback routines must work correctly at that IRQL.

## See also

[CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock)

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

[CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp)

[CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex)

[CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp)

[CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock)

[CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp)

[IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IO_CSQ_IRP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize)

[IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex)

[IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)

[IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp)