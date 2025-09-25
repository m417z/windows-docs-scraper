# IoCsqInsertIrpEx function

## Description

The **IoCsqInsertIrpEx** routine inserts an IRP into the driver's cancel-safe IRP queue.

## Parameters

### `Csq` [in, out]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the driver's cancel-safe IRP queue. This structure must have been initialized by [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize) or [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex).

### `Irp` [in, out]

Pointer to the IRP to be queued.

### `Context` [out, optional]

Pointer to an [IO_CSQ_IRP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. **IoCsqInsertIrpEx** initializes this structure with context information for the inserted IRP. The driver passes this value to [IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp) to delete the IRP from the queue. *Context* can be **NULL** if the driver will not use **IoCsqRemoveIrp** to remove this IRP from the queue.

### `InsertContext` [in, optional]

Pointer to a driver-defined context value. This parameter is passed to the driver's [CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex) routine, if it has one. Otherwise, this parameter is ignored.

## Return value

If the *Csq* parameter was initialized with [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize), **IoCsqInsertIrpEx** always returns STATUS_SUCCESS. If *Csq* was initialized with **IoCsqInitializeEx**, **IoCsqInsertIrpEx** returns the value that was returned by the driver's [CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex) routine.

## Remarks

**IoCsqInsertIrpEx** uses the queue's dispatch routines to insert the IRP. The **IoCsqInsertIrpEx** routine:

1. Calls the queue's [CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock) routine to lock the queue.
2. If the queue's [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure was initialized by [IoCsqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitialize), **IoCsqInsertIrpEx** calls the queue's [CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp) routine to insert the IRP. If the queue's **IO_CSQ** structure was initialized by [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex), **IoCsqInsertIrpEx** calls the queue's [CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex) routine to insert the IRP, and passes the *InsertContext* parameter as the *InsertContext* parameter of *CsqInsertIrpEx*.
3. Calls the queue's [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) routine to unlock the queue.

If the IRP to be inserted has already been canceled, **IoCsqInsertIrpEx** does not attempt to insert the IRP into the queue.

For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

Note that **IoCsq*Xxx*** routines use the **DriverContext**[3] member of the IRP to hold IRP context information. Drivers that use these routines to queue IRPs must leave that member unused.

Callers of **IoCsqInsertIrpEx** must be running at an IRQL <= DISPATCH_LEVEL. The driver's callback routines must work correctly at this IRQL.

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

[IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)

[IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp)