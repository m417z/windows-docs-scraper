# RemoveTailList function

## Description

The **RemoveTailList** routine removes an entry from the end of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that serves as the list header.

## Return value

**RemoveTailList** returns a pointer to the entry that was at the tail of the list. If the list is empty, **RemoveTailList** returns *ListHead*.

## Remarks

**RemoveTailList** removes the last entry from the list by setting *ListHead*->**Blink** to point to the second-to-last entry in the list. The routine sets the **Flink** member of the new first entry to *ListHead*. In the event the list is empty, this is effectively a no-op.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **InsertHeadList** can be running at any IRQL. If **InsertHeadList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)