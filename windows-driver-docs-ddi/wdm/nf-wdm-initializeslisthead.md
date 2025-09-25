# InitializeSListHead function

## Description

The **InitializeSListHead** routine (or ExInitializeSListHead) initializes an [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that represents the head of a sequenced singly linked list.

## Parameters

### `SListHead` [in]

A pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to initialize. The structure must be 16-byte aligned on 64-bit platforms.

## Remarks

For more information about using this routine to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **InitializeSListHead or ExInitializeSListHead** can be running at any IRQL. If **ExInitializeSListHead** is called at IRQL >= DISPATCH_LEVEL the storage for *SListHead* must be resident.

## See also

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist)

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpopentryslist)

[ExInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpushentryslist)

[ExQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exquerydepthslist)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)