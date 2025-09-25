# __RxSynchronizeBlockingOperations function

## Description

**__RxSynchronizeBlockingOperations** synchronizes blocking I/O requests to the same work queue.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT of the operation being synchronized.

### `Fcb` [in]

A pointer to the FCB.

### `BlockingIoQ` [in, out]

A pointer to the LIST_ENTRY for the queue.

### `DropFcbLock` [in]

A Boolean value that indicates if the FCB resource should be released. If this parameter is **TRUE**, then the FCB resource will be released.

## Return value

**__RxSynchronizeBlockingOperations** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The I/O request and the associated RX_CONTEXT was canceled. |
| **STATUS_PENDING** | The *RxContext* was for an asynchronous operation and the *RxContext* has been added to the queue. |

## Remarks

The **__RxSynchronizeBlockingOperations** routine synchronizes blocking I/O requests to the same work queue. RDBSS uses **__RxSynchronizeBlockingOperations** internally to synchronize named pipe operations. The work queue is the queue referenced by the file object extension (FOBX) associated with the *Fcb*.

A network mini-redirector may use **__RxSynchronizeBlockingOperations** to synchronize operations on a separate queue that is maintained by the network mini-redirector.

If *RxContext* is marked for an asynchronous operation, **__RxSynchronizeBlockingOperations** will add the *RxContext* to the queue and return STATUS_PENDING. If *RxContext* is marked for a synchronous operation, **__RxSynchronizeBlockingOperations** will block and *RxContext* is resumed when a call is made to [RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially).

If the blocking I/O request was canceled, **__RxSynchronizeBlockingOperations** returns STATUS_CANCELLED to indicate the error.

The **SyncEvent** member of the RX_CONTEXT structure pointed to by *RxContext* must have been reset before calling **__RxSynchronizeBlockingOperations**. The FCB resource must be locked before calling **__RxSynchronizeBlockingOperations** if the *DropFcbLock* parameter is set to **TRUE**.

The following two macros are defined on Windows Server 2003 or later for calling **__RxSynchronizeBlockingOperations**:

**RxSynchronizeBlockingOperations** - calls with the *DropFcbLock* parameter set to **FALSE**.

**RxSynchronizeBlockingOperationsAndDropFcbLock** - calls with the *DropFcbLock* parameter set to **TRUE**.

## See also

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)