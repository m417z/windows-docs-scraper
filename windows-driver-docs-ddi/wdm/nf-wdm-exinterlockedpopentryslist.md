# ExInterlockedPopEntrySList macro

## Description

The **ExInterlockedPopEntrySList** routine atomically removes the first entry from a sequenced singly linked list.

## Parameters

### `ListHead` [in, out]

A pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the header for the sequenced singly linked list. *ListHead* must have been initialized by calling [ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead).

### `Lock` [in, out]

A pointer to a **KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock). You must use this spin lock only with the **ExInterlocked*Xxx*List** routines.

## Syntax

```cpp
NTKERNELAPI
PSLIST_ENTRY
FASTCALL
ExInterlockedPopEntrySList (
    _Inout_ PSLIST_HEADER ListHead,
    _Inout_opt_ _Requires_lock_not_held_(*_Curr_) PKSPIN_LOCK Lock
    );
```
## Return value

**ExInterlockedPopEntrySList** returns a pointer to the first [**SLIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry) structure on the list. If the list was empty, the routine returns NULL.

## Remarks

For more information about using this routine to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

On Windows 2000, drivers must use the **-D_WIN2K_COMPAT_SLIST_USAGE** switch to successfully link code that uses **ExInterlockedPopEntrySList**.

**ExInterlockedPopEntrySList** can be called at any IRQL. The storage for the *ListHead* parameter must be resident at all IRQLs.

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)

[ExInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedpushentryslist)

[ExInterlockedRemoveHeadList](https://learn.microsoft.com/previous-versions/ff545427(v=vs.85))

[ExQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exquerydepthslist)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)