# LIST_ENTRY structure

## Description

A **LIST_ENTRY** structure describes an entry in a doubly linked list or serves as the header for such a list.

## Members

### `Flink`

For a **LIST_ENTRY** structure that serves as a list entry, the **Flink** member points to the next entry in the list or to the list header if there is no next entry in the list.

For a **LIST_ENTRY** structure that serves as the list header, the **Flink** member points to the first entry in the list or to the LIST_ENTRY structure itself if the list is empty.

### `Blink`

For a **LIST_ENTRY** structure that serves as a list entry, the **Blink** member points to the previous entry in the list or to the list header if there is no previous entry in the list.

For a **LIST_ENTRY** structure that serves as the list header, the **Blink** member points to the last entry in the list or to the **LIST_ENTRY** structure itself if the list is empty.

## Remarks

A **LIST_ENTRY** structure that describes the list head must have been initialized by calling [InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-initializelisthead).

A driver can access the **Flink** or **Blink** members of a **LIST_ENTRY**, but the members must only be updated by the system routines supplied for this purpose.

For more information about how to use **LIST_ENTRY** structures to implement a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

## See also

[ExInterlockedInsertHeadList](https://learn.microsoft.com/previous-versions/ff545397(v=vs.85))

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedRemoveHeadList](https://learn.microsoft.com/previous-versions/ff545427(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-initializelisthead)

[InsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-insertheadlist)

[InsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-inserttaillist)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-islistempty)

[RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-removeentrylist)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-removetaillist)