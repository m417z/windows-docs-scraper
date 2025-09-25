# ExInterlockedRemoveHeadList function

## Description

The **ExInterlockedRemoveHeadList** routine removes an entry from the beginning of a doubly linked list of [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structures.

## Parameters

### `ListHead` [in, out]

A pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that serves as the list header.

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Return value

**ExInterlockedRemoveHeadList** returns a pointer to the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure removed from the list. If the list was empty, the routine returns **NULL**.

## Remarks

**ExInterlockedRemoveHeadList** performs a similar operation as [RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist), but atomically. Do not mix atomic and non-atomic calls on the same list.

For more information about using this routine to implement a doubly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

The **ExInterlockedRemoveHeadList** routine can be called at any IRQL. The storage for the *ListHead* parameter must be resident at all IRQLs.

## See also

[ExInterlockedInsertHeadList](https://learn.microsoft.com/previous-versions/ff545397(v=vs.85))

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[InitializeListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[RemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeheadlist)