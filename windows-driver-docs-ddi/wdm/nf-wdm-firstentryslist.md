# FirstEntrySList function

## Description

The **FirstEntrySList** routine returns the first entry in a sequenced singly linked list.

## Parameters

### `SListHead` [in]

Pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the header for the sequenced singly linked list.

## Return value

**FirstEntrySList** returns a pointer to the first [SLIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry) structure on the list. If the list is empty, the routine returns **NULL**.

## Remarks

Unlike other sequenced singly linked list routines, the **FirstEntrySList** routine is not atomic. For more information about sequenced singly linked lists, see [Sequenced Singly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists). Callers of this routine can run at any level. If called at IRQL >= DISPATCH_LEVEL, the storage for **ListHead** must be resident.

## See also

[SLIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry)

[SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)