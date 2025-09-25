# InsertTailList function

## Description

The **InsertTailList** routine inserts an entry at the tail of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the head of the list.

### `Entry` [in, out]

Pointer to a [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the entry to be inserted in the list.

## Remarks

**InsertTailList** updates *ListHead*->**Blink** to point to *Entry*. It updates *Entry*->**Blink** to point to the old last entry in the list, and sets *Entry*->**Flink** to *ListHead*. The **Flink** of the previous last entry is updated to point to *Entry* as well.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **InsertTailList** can be running at any IRQL. If **InsertTailList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[InsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)