# RemoveEntryList function

## Description

The **RemoveEntryList** routine removes an entry from a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `Entry` [in]

Pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the entry to be removed.

## Return value

**RemoveEntryList** returns **TRUE** if, after removal of the designated entry, the list is empty. Otherwise, the routine returns **FALSE** to indicate that the resulting list still contains one or more entries. For information, see the **Remarks** section below.

## Remarks

**RemoveEntryList** removes the entry by setting the **Flink** member of the entry before *Entry* to point to the entry after *Entry*, and the **Blink** member of the entry after *Entry* to point to the entry before *Entry*.

The return value can be used to detect when the last entry is removed from the list. An empty list consists of a list head only and no list entries.

Typically, *Entry* points to an entry in a list and not to the list head. However, *Entry* can point to a list head, in which case the routine removes the list head from the list to produce a headless list. When **RemoveEntryList** is used in this way, the return value should typically be ignored. To determine whether a list is empty, use the [IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty) routine.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **RemoveEntryList** can be running at any IRQL. If **RemoveEntryList** is called at IRQL >= DISPATCH_LEVEL, the storage for the list entries must be resident.

## See also

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)