# PushEntryList function

## Description

The **PushEntryList** routine inserts an entry at the beginning of a singly linked list of [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure that serves as the list header.

### `Entry` [in, out]

Pointer to SINGLE_LIST_ENTRY structure that represents the entry to be inserted on the list.

## Remarks

**PushEntryList** sets *ListHead*->**Next** to *Entry*, and *Entry*->**Next** to point to the old first entry of the list.

For information about using this routine when implementing a singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **PushEntryList** can be running at any IRQL. If **PushEntryList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[ExInterlockedPushEntryList](https://learn.microsoft.com/previous-versions/ff545418(v=vs.85))

[PopEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-popentrylist)