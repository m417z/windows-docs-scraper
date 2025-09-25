# RemoveHeadList function

## Description

The **RemoveHeadList** routine removes an entry from the beginning of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that serves as the list header.

## Return value

**RemoveHeadList** returns a pointer to the entry removed from the list. If the list is empty, **RemoveHeadList** returns *ListHead*.

## Remarks

**RemoveHeadList** removes the first entry from the list by setting *ListHead*->**Flink** to point to the second entry in the list. The routine sets the **Blink** member of the second entry to *ListHead*. In the event the list is empty, this is effectively a no-op.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **RemoveHeadList** can be running at any IRQL. If **RemoveHeadList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[ExInterlockedRemoveHeadList](https://learn.microsoft.com/previous-versions/ff545427(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)