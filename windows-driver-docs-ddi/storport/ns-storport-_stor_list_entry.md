# STOR_LIST_ENTRY structure

## Description

A **STOR_LIST_ENTRY** structure describes an entry in a doubly linked list or serves as the header for such a list.

## Members

### `Flink`

For a **LIST_ENTRY** structure that serves as a list entry, the **Flink** member points to the next entry in the list or to the list header if there is no next entry in the list.

For a **LIST_ENTRY** structure that serves as the list header, the **Flink** member points to the first entry in the list or to the LIST_ENTRY structure itself if the list is empty.

### `Blink`

For a **LIST_ENTRY** structure that serves as a list entry, the **Blink** member points to the previous entry in the list or to the list header if there is no previous entry in the list.

For a **LIST_ENTRY** structure that serves as the list header, the **Blink** member points to the last entry in the list or to the **LIST_ENTRY** structure itself if the list is empty.

## Remarks

A **STOR_LIST_ENTRY** structure that describes the list head must have been initialized by calling [**StorPortInitializeListHead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializelisthead).

A driver can access the **Flink** or **Blink** members of a **STOR_LIST_ENTRY**, but the members must only be updated by the system routines supplied for this purpose.

For more information about how to use **STOR_LIST_ENTRY** structures to implement a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

## See also

[**InitializeListHead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[**InsertHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist)

[**InsertTailList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-inserttaillist)

[**IsListEmpty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[**RemoveEntryList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist)

[**RemoveHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[**RemoveTailList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)

[**StorPortInterlockedInsertHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinsertheadlist)

[**StorPortInterlockedInsertTailList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinserttaillist)

[**StorPortInterlockedRemoveHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedremoveheadlist)