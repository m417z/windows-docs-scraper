# ExInterlockedPopEntryList function

## Description

The **ExInterlockedPopEntryList** routine atomically removes an entry from the beginning of a singly linked list of [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structures.

## Parameters

### `ListHead` [in, out]

A pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure that serves as the list header. The storage for *ListHead* must be resident at all IRQLs.

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Return value

**ExInterlockedPopEntryList** returns a pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure removed from the list. If the list was empty, the routine returns **NULL**.

## Remarks

**ExInterlockedPopEntryList** performs the same operation as [PopEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-popentrylist), but atomically. Do not mix atomic and non-atomic calls on the same list.

For more information about using this routine to implement a singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

The **ExInterlockedPopEntryList** routine can be called at any IRQL. The storage for the *ListHead* parameter must be resident at all IRQLs.

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)

[ExInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpopentryslist)

[ExInterlockedPushEntryList](https://learn.microsoft.com/previous-versions/ff545418(v=vs.85))

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[PopEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-popentrylist)