# ExInterlockedPushEntrySList macro

## Description

The **ExInterlockedPushEntrySList** routine atomically inserts an entry at the beginning of a sequenced singly linked list.

## Parameters

### `ListHead`

A pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the header for the sequenced singly linked list. *ListHead* must have been initialized by calling [ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead).

### `ListEntry`

A pointer to the caller-allocated entry to be inserted.

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Syntax

```cpp
NTKERNELAPI
PSLIST_ENTRY
FASTCALL
ExInterlockedPushEntrySList (
    _Inout_ PSLIST_HEADER ListHead,
    _Inout_ __drv_aliasesMem PSLIST_ENTRY ListEntry,
    _Inout_opt_ _Requires_lock_not_held_(*_Curr_) PKSPIN_LOCK Lock
    );
```

## Return value

If there were entries on the specified list, **ExInterlockedPushEntrySList** returns a pointer to the first [**SLIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry) structure that was an entry on the list; otherwise, it returns NULL.

## Remarks

For more information about using this routine to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

On Windows 2000, drivers must use the **-D_WIN2K_COMPAT_SLIST_USAGE** switch to successfully link code that uses **ExInterlockedPushEntrySList**.

The **ExInterlockedPushEntrySList** routine can be called at any IRQL. The storage for the *ListHead* parameter and the list entries must be resident at all IRQLs.

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)

[ExInterlockedInsertTailList](https://learn.microsoft.com/previous-versions/ff545402(v=vs.85))

[ExInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpopentryslist)

[ExQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exquerydepthslist)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)