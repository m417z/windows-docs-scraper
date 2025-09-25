# ExQueryDepthSList function

## Description

The **ExQueryDepthSList** routine returns the number of entries currently in a given sequenced singly linked list.

## Parameters

### `SListHead` [in]

A pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the header for the sequenced singly linked list. *SListHead* must have been initialized by calling [ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead).

## Return value

**ExQueryDepthSList** returns the current number of entries in the list.

## Remarks

For more information about using this routine to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)

[ExInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpopentryslist)

[ExInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpushentryslist)