# RxSetMinirdrCancelRoutine function

## Description

**RxSetMinirdrCancelRoutine** is called by a network mini-redirector driver to set up a network mini-redirector cancel routine for an RX_CONTEXT structure.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure.

### `MRxCancelRoutine` [in]

A pointer to a cancel routine.

## Return value

**RxSetMinirdrCancelRoutine** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The *RxContext* parameter was already canceled. The error will be returned if the **Flags** member of *RxContext* has the RX_CONTEXT_FLAG_CANCELLED bit set. |

## Remarks

The **RxSetMinirdrCancelRoutine** routine sets the **MRxCancelRoutine** member of the *RxContext* parameter to the value of the *MRxCancelRoutine* parameter. This operation is protected by a spinlock.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxPrepareContextForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxpreparecontextforreuse)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)