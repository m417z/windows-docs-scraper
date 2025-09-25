# _SLIST_ENTRY structure

## Description

An **SLIST_ENTRY** structure describes an entry in a sequenced singly linked list.

## Members

### `Next`

Pointer to the next entry in the list, or **NULL** if there is no next entry in the list.

## Remarks

A driver can access the **Next** member of a **SLIST_ENTRY**, but must only be updated by the system routines supplied for this purpose.

On 64-bit platforms, **SLIST_ENTRY** structures must be 16-byte aligned. Drivers can use DECLSPEC_ALIGN(MEMORY_ALLOCATION_ALIGNMENT) to ensure the proper alignment of **SLIST_ENTRY**.

For more information about how to use **SLIST_ENTRY** structures to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

## See also

[ExInterlockedFlushSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedflushslist)

[ExInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpopentryslist)

[ExInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpushentryslist)