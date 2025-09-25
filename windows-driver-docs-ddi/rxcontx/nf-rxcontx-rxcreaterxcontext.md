# RxCreateRxContext function

## Description

**RxCreateRxContext** allocates a new RX_CONTEXT structure and initializes the data structure.

## Parameters

### `Irp` [in, optional]

A pointer to the IRP to be encapsulated by this RX_CONTEXT structure.

### `RxDeviceObject` [in]

A pointer to the device object to which this RX_CONTEXT and IRP apply.

### `InitialContextFlags` [in]

The set of initial values for the **Flags** member of the RX_CONTEXT data structure to be stored in the RX_CONTEXT structure. These initial values can be any combination of the following enumerations:

#### RX_CONTEXT_FLAG_WAIT

When this value is set, the IRP should be not be posted for later execution by the file system process, but should be waited on to complete.

#### RX_CONTEXT_FLAG_MUST_SUCCEED

When this value is set, the operation must succeed. This value is not currently used by RDBSS, but it may be used by network mini-redirector drivers.

#### RX_CONTEXT_FLAG_MUST_SUCCEED_NONBLOCKING

When this value is set, the operation must succeed for non-blocking operations. This value is not currently used by RDBSS, but it may be used by network mini-redirector drivers.

## Return value

**RxCreateRxContext** returns a pointer to an allocated RX_CONTEXT data structure on success or a **NULL** pointer on failure.

## Remarks

**RxCreateRxContext** calls [RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext) to initialize the newly created RX_CONTEXT structure before returning.

**RxCreateRxContext** allocates non-paged pool memory when creating a new RX_CONTEXT data structure and sets the following value in the Flags member of the RX_CONTEXT:

When this value is set, the RX_CONTEXT structure was allocated from non-paged pool memory.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)