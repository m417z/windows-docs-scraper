# RxCompleteRequest function

## Description

**RxCompleteRequest** completes the IRP request associated with an RX_CONTEXT structure.

## Parameters

### `pContext`

A pointer to the RX_CONTEXT. This parameter contains the IRP requesting the operation to complete.

### `Status`

The status value to return when the IRP request is complete. This is the value that will be stored in the **IoStatus.Status** member of the associated IRP on completion.

## Return value

**RxCompleteRequest** returns the value of the *Status* parameter.

## Remarks

The **RxCompleteRequest** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally to complete an I/O request packet.

**RxCompleteRequest** internally calls **RxCompleteRequest_Real** to complete the request. Before calling **RxCompleteRequest_Real**, the **RxCompleteRequest** routine checks the value of the **LoudCompletionString** member in the RX_CONTEXT structure pointed to by the *RxContext* parameter and prints extra debugging information if *Status* is not equal to STATUS_SUCCESS.

## See also

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)