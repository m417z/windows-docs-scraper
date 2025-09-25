# ExFreeToPagedLookasideList function

## Description

The **ExFreeToPagedLookasideList** routine returns a pageable entry to the given lookaside list or to paged pool.

## Parameters

### `Lookaside` [in, out]

A pointer to the [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller already initialized with [ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist), which the caller already initialized with **ExInitializePagedLookasideList**.

### `Entry` [in]

A pointer to the entry to be freed. The caller obtained this pointer from a preceding call to [ExAllocateFromPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefrompagedlookasidelist).

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

**ExFreeToPagedLookasideList** is the reciprocal of **ExAllocateFromPagedLookasideList**. It releases a caller-allocated entry back to the caller's lookaside list or to paged pool when that entry is no longer in use.

The same entry can be reallocated or another entry can be allocated later with a subsequent call to **ExAllocateFromPagedLookasideList**. The user of a lookaside list can allocate and free such entries dynamically, as needed, until it calls **ExDeletePagedLookasideList**. **ExDeletePagedLookasideList** releases any outstanding entries in the list before it clears the system state for the given lookaside list and returns control.

If the specified lookaside list has not yet reached the system-determined maximum number of entries, **ExFreeToPagedLookasideList** inserts the given entry at the front of the list. Otherwise, the buffer at *Entry* is released back to paged pool using the caller-supplied *Free* routine, if any, that was set up when the lookaside list was initialized or **ExFreePool**.

On Windows 2000, drivers must use the **-D_WIN2K_COMPAT_SLIST_USAGE** switch to successfully link code that uses **ExFreeToPagedLookasideList**.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExAllocateFromPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefrompagedlookasidelist)

[ExDeletePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletepagedlookasidelist)

[ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)