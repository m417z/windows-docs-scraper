# RxDereferenceAndDeleteRxContext_Real function

## Description

**RxDereferenceAndDeleteRxContext_Real** dereferences an RX_CONTEXT data structure and if the **ReferenceCount** member goes to zero, then it deallocates and removes the specified RX_CONTEXT structure from the RDBSS in-memory data structures.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure to be removed.

## Remarks

**RxDereferenceAndDeleteRxContext_Real** is called by routines other than **RxCompleteRequest** during asynchronous requests that touch the *RxContext* parameter in either the initiating thread or in some other thread. Thus, the RX_CONTEXT data structure is reference counted and finalized on the last dereference.

If the **ReferenceCount** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter is not zero after being dereferenced (decremented) by the **RxDereferenceAndDeleteRxContext_Real** routine, then **RxDereferenceAndDeleteRxContext_Real** causes the system to ASSERT on checked builds.

The **RxDereferenceAndDeleteRxContext_Real** routine makes a number of specific checks before removing an RX_CONTEXT. These checks include the following:

* If the **AcquireReleaseFcbTrackerX** member is 0, then **RxDereferenceAndDeleteRxContext_Real** causes the system to ASSERT on checked builds.
* If the **NumberOfActiveContexts** member of the associated RDBSS_DEVICE_OBJECT structure pointed to ***RxContext*****->RxDeviceObject** is not zero after being dereferenced (decremented) and the **StartStopContext.pStopContext** member of the associated RDBSS_DEVICE_OBJECT structure is not **NULL**, then **RxDereferenceAndDeleteRxContext_Real** will signal the SyncEvent on the RX_CONTEXT structure in the **StartStopContext.pStopContext** member.

If the RX_CONTEXT structure was allocated from non-page pool memory (the **Flags** member of the RX_CONTEXT structure has the RX_CONTEXT_FLAG_FROM_POOL option set), then the RX_CONTEXT structure pointed to by the *RxContext* parameter will be returned to an internal RDBSS lookaside list or to non-paged pool memory.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)