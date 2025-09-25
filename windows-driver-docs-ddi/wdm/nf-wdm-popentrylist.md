# PopEntryList function

## Description

The **PopEntryList** routine removes the first entry from a singly linked list of [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structures.

## Parameters

### `ListHead` [in, out]

Pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure that represents the head of the list. On return, *ListHead*->**Next** points to the beginning of the list with the first entry removed.

## Return value

**PopEntryList** returns a pointer to the entry removed from the list, or **NULL** if the list is currently empty.

## Remarks

**PopEntryList** removes the first entry from the list by setting *ListHead*->**Next** to point to the second entry in the list.

For information about using this routine when implementing a singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **PopEntryList** can be running at any IRQL. If **PopEntryList** is called at IRQL >= DISPATCH_LEVEL, the storage for *ListHead* and the list entries must be resident.

## See also

[ExInterlockedPopEntryList](https://learn.microsoft.com/previous-versions/ff545408(v=vs.85))

[PushEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pushentrylist)