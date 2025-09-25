# SINGLE_LIST_ENTRY structure

## Description

A **SINGLE_LIST_ENTRY** structure describes an entry in a singly linked list, or serves as the header for such a list.

## Members

### `Next`

For a **SINGLE_LIST_ENTRY** that serves as a list entry, the **Next** member points to the next entry in the list, or **NULL** if there is no next entry in the list. For a **SINGLE_LIST_ENTRY** that serves as the list header, the **Next** member points to the first entry in the list, or **NULL** if the list is empty.

## Remarks

If a **SINGLE_LIST_ENTRY** structure is used as a list head, initialize the **Next** member of the structure to be **NULL**.

A driver can access the **Next** member of a **SINGLE_LIST_ENTRY**, but (other than initializing a list head) **Next** must only be updated by the system routines supplied for this purpose.

For more information about how to use **SINGLE_LIST_ENTRY** structures to implement a singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

## See also

[ExInterlockedPopEntryList](https://learn.microsoft.com/previous-versions/ff545408(v=vs.85))

[ExInterlockedPushEntryList](https://learn.microsoft.com/previous-versions/ff545418(v=vs.85))

[PopEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-popentrylist)

[PushEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-pushentrylist)