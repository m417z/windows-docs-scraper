# ExInterlockedPushEntryList function

## Description

The **ExInterlockedPushEntryList** routine atomically inserts an entry at the beginning of a singly linked list of [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structures.

## Parameters

### `ListHead` [in, out]

A pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure that serves as the list header. The storage for *ListHead* must be resident at all IRQLs.

### `ListEntry` [in, out]

A pointer to the [SINGLE_LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-single_list_entry) structure that represents the entry to be inserted into the list. The storage for *ListEntry* must be resident at all IRQLs.

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Return value

**ExInterlockedPushEntryList** returns a pointer to the first entry of the list before the new entry was inserted. If the list was empty, the routine returns **NULL**.

## Remarks

**ExInterlockedPushEntryList** performs the same operation as [PushEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pushentrylist), but atomically. Do not mix atomic and non-atomic calls on the same list.

For more information about using this routine to implement a singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

The **ExInterlockedPushEntryList** routine can be called at any IRQL. The storage for the *ListHead* parameter and the list entries must be resident at all IRQLs.

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedPopEntryList](https://learn.microsoft.com/previous-versions/ff545408(v=vs.85))

[ExInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpushentryslist)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[PushEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pushentrylist)