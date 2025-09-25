# ExFreeToNPagedLookasideList function

## Description

The **ExFreeToNPagedLookasideList** routine returns a nonpaged entry to the given lookaside list or to nonpaged pool.

## Parameters

### `Lookaside` [in, out]

A pointer to the [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller already initialized with [ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist).

### `Entry` [in]

A pointer to the entry to be freed. The caller obtained this pointer from a preceding call to [ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist).

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

**ExFreeToNPagedLookasideList** is the reciprocal of **ExAllocateFromNPagedLookasideList**. It releases a caller-allocated entry back to the caller's lookaside list or to nonpaged pool when that entry is no longer in use.

The same entry can be reallocated or another entry allocated later with a subsequent call to **ExAllocateFromNPagedLookasideList**. The user of the lookaside list can allocate and free such entries dynamically on an as-needed basis until it calls **ExDeleteNPagedLookasideList**, which releases any outstanding entries in the list before it clears the system state for the given lookaside list and returns control.

If the specified lookaside list has not yet reached the system-determined maximum number of entries, **ExFreeToNPagedLookasideList** inserts the given entry at the front of the list. Otherwise, the buffer at *Entry* is released to nonpaged pool using the caller-supplied *Free* routine, if any, that was set up when the lookaside list was initialized or **ExFreePool**.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist)

[ExDeleteNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletenpagedlookasidelist)

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)