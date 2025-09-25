# RxPrepareContextForReuse function

## Description

**RxPrepareContextForReuse** prepares an RX_CONTEXT data structure for reuse by resetting all of the operation-specific allocations and acquisitions that have been made (the **ReferenceCount** member to the RX_CONTEXT structure is set to zero). Parameters that have been obtained from the IRP are not modified.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure.

## Remarks

The **RxPrepareContextForReuse** routine checks that several operation-specific members in the RX_CONTEXT structure are **NULL** before setting the **ReferenceCount** member to zero. These operation-specific tests that must be met include the following:

* If the **MajorFunction** member of the associated IRP is IRP_MJ_CREATE, then the **Create.CanonicalNameBuffer** member must be **NULL**.
* If the **MajorFunction** member of the associated IRP is IRP_MJ_READ or IRP_MJ_WRITE, then the **RxContextSerializationQLinks.Flink** and **RxContextSerializationQLinks.Blink** members must be **NULL**.

If either of the above conditions are not met, **RxPrepareContextForReuse** causes the system to ASSERT on checked builds.

The **RxPrepareContextForReuse** routine would normally only be used by network mini-redirector drivers that reinitialize RX_CONTEXT structures directly.

## See also

[RxCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest)

[RxCompleteRequest_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxcompleterequest_real)

[RxCreateRxContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxDereferenceAndDeleteRxContext_Real](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxdereferenceanddeleterxcontext_real)

[RxInitializeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxinitializecontext)

[RxResumeBlockedOperations_Serially](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxresumeblockedoperations_serially)

[__RxSynchronizeBlockingOperations](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-__rxsynchronizeblockingoperations)

[__RxSynchronizeBlockingOperationsMaybeDroppingFcbLock](https://learn.microsoft.com/windows-hardware/drivers/ifs/--rxsynchronizeblockingoperationsmaybedroppingfcblock)