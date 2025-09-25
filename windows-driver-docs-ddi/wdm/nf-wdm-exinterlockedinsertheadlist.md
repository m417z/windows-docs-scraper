# ExInterlockedInsertHeadList function

## Description

The **ExInterlockedInsertHeadList** routine atomically inserts an entry at the beginning of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

A pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that serves as the list header.

### `ListEntry` [in, out]

A pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that represents the entry to be inserted into the list.

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Return value

**ExInterlockedInsertHeadList** returns a pointer to the first entry of the list before the new entry was inserted. If the list was empty, the routine returns **NULL**.

## Remarks

**ExInterlockedInsertHeadList** performs the same operation as [InsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist), but atomically. Do not mix atomic and non-atomic calls on the same list.

For more information about using this routine to implement a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

The **ExInterlockedInsertHeadList** routine can be called at any IRQL. The storage for the *ListHead* parameter and the list entries must be resident at all IRQLs.

## See also

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedRemoveHeadList](https://learn.microsoft.com/previous-versions/ff545427(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[InsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)