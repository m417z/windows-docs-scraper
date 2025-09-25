# InsertHeadList function

## Description

The **InsertHeadList** routine inserts an entry at the head of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the head of the list.

### `Entry` [in, out]

Pointer to a [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the entry to be inserted into the list.

## Remarks

**InsertHeadList** updates *ListHead*->**Flink** to point to *Entry*. It updates *Entry*->**Flink** to point to the old first entry in the list, and sets *Entry*->**Blink** to *ListHead*. The **Blink** field of the original first entry is also updated to point to *Entry*.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **InsertHeadList** can be running at any IRQL. If **InsertHeadList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[ExInterlockedInsertHeadList](https://learn.microsoft.com/previous-versions/ff545397(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[InsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-inserttaillist)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)