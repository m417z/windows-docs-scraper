# InitializeListHead function

## Description

The **InitializeListHead** routine initializes a [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the head of a doubly linked list.

## Parameters

### `ListHead` [out]

Pointer to a [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that serves as the list header.

## Remarks

The **InitializeListHead** routine sets the **Flink** and **Blink** members of *ListHead* to point to *ListHead*.

For information about using this routine when implementing a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **InitializeListHead** can be running at any IRQL. If **InitializeListHead** is called at IRQL >= DISPATCH_LEVEL the storage for *ListHead* must be resident.

## See also

[ExInterlockedInsertHeadList](https://learn.microsoft.com/previous-versions/ff545397(v=vs.85))

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedPopEntryList](https://learn.microsoft.com/previous-versions/ff545408(v=vs.85))

[ExInterlockedPushEntryList](https://learn.microsoft.com/previous-versions/ff545418(v=vs.85))

[ExInterlockedRemoveHeadList](https://learn.microsoft.com/previous-versions/ff545427(v=vs.85))

[InsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist)

[InsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-inserttaillist)

[IsListEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-islistempty)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[PopEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-popentrylist)

[PushEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pushentrylist)

[RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)

[RemoveTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removetaillist)