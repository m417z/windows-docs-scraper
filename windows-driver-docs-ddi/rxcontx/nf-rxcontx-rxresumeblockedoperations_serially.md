# RxResumeBlockedOperations_Serially function

## Description

**RxResumeBlockedOperations_Serially** wakes up the next waiting thread, if any, on the serialized blocking I/O queue.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure of the operation being synchronized.

### `BlockingIoQ` [in, out]

A pointer to the blocking I/O queue.

## Remarks

**RxResumeBlockedOperations_Serially** wakes up the next work item on a serialized blocking I/O queue, if one exists. The FCB structure must still be valid because of the reference that is being held by the I/O system on the file object, thereby preventing a close operation.

A serialized blocking I/O queue is one for which the **FlagsForLowIo** member of the RX_CONTEXT structure pointed to by *RxContext* has the RXCONTEXT_FLAG4LOWIO_PIPE_SYNC_OPERATION bit set.

**RxResumeBlockedOperations_Serially** performs this operation by calling **RxFsdPostRequest** to post the operation to a worker thread.

The **RxResumeBlockedOperations_Serially** routine is normally not called directly by a network mini-redirector driver, but is called internally by RDBSS when processing synchronous read and write operations on a named pipe that requires a serialized queue.

A network mini-redirector may need to call **RxResumeBlockedOperations_Serially** if an RX_CONTEXT has been placed on a synchronization queue using **__RxSynchronizeBlockingOperations** or **__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock**.

## See also

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxFsdPostRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfsdpostrequest)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)