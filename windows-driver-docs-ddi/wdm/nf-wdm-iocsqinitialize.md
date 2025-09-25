# IoCsqInitialize function

## Description

The **IoCsqInitialize** routine initializes the driver's cancel-safe IRP queue dispatch table.

## Parameters

### `Csq` [out]

Pointer to the [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to be initialized by **IoCsqInitialize**.

### `CsqInsertIrp` [in]

Pointer to the driver-defined [CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp) function for the driver's cancel-safe IRP queue.

### `CsqRemoveIrp` [in]

Pointer to the driver-defined [CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp) function for the driver's cancel-safe IRP queue.

### `CsqPeekNextIrp` [in]

Pointer to the driver-defined [CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp) function for the driver's cancel-safe IRP queue.

### `CsqAcquireLock` [in]

Pointer to the driver-defined [CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock) function for the driver's cancel-safe IRP queue.

### `CsqReleaseLock` [in]

Pointer to the driver-defined [CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock) function for the driver's cancel-safe IRP queue.

### `CsqCompleteCanceledIrp` [in]

Pointer to the driver-defined [CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp) function for the driver's cancel-safe IRP queue.

## Return value

This routine returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

The **IoCsqInitialize** routine initializes an [IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes a driver's cancel-safe IRP queue. Drivers can also use [IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex) to create an IRP queue with extended capabilities. For more information, see [Cancel-Safe IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/cancel-safe-irp-queues).

Note that **IoCsq*Xxx*** routines use the **DriverContext**[3] member of the IRP to hold IRP context information. Drivers that use these routines to queue IRPs must leave that member unused.

## See also

[CsqAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_acquire_lock)

[CsqCompleteCanceledIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_complete_canceled_irp)

[CsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp)

[CsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_insert_irp_ex)

[CsqPeekNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_peek_next_irp)

[CsqReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_release_lock)

[CsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_csq_remove_irp)

[IO_CSQ](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoCsqInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinitializeex)

[IoCsqInsertIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirp)

[IoCsqInsertIrpEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqinsertirpex)

[IoCsqRemoveIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremoveirp)

[IoCsqRemoveNextIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocsqremovenextirp)