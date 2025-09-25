# RxCompleteRequest_Real function

## Description

**RxCompleteRequest_Real** completes the IRP request associated with an RX_CONTEXT structure.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure associated with the IRP to complete.

### `Irp` [in]

A pointer to the IRP to complete.

### `Status` [in]

The status value to return when the IRP request is complete. This is the value that will be stored in the **IoStatus.Status** member of the associated IRP on completion.

## Remarks

The **RxCompleteRequest_Real** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally to complete an I/O request packet.

If a **NULL** value is passed in for *Irp*, then **RxCompleteRequest_Real** will log this as an error in checked builds. If a non-**NULL** value is passed in for *RxContex*t, then **RxCompleteRequest_Real** internally calls **RxDereferenceAndDeleteRxContext** with the passed in *RxContext* parameter to dereference the RX_CONTEXT structure.

## See also

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)