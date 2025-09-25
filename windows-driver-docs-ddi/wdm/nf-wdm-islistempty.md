# IsListEmpty function

## Description

The **IsListEmpty** routine indicates whether a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures is empty.

## Parameters

### `ListHead` [in]

Pointer to a [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the head of the list.

## Return value

**IsListEmpty** returns **TRUE** if there are currently no entries in the list and **FALSE** otherwise.

## Remarks

**IsListEmpty** returns **TRUE** if *ListHead*->**Flink** refers back to *ListHead*.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **IsListEmpty** can be running at any IRQL. If **IsListEmpty** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* must be resident.

## See also

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)