# ExAllocateFromPagedLookasideList function

## Description

The **ExAllocateFromPagedLookasideList** routine returns a pointer to a paged entry from the given lookaside list, or it returns a pointer to a newly allocated paged entry.

## Parameters

### `Lookaside` [in, out]

A pointer to the [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller already initialized with [ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist).

## Return value

**ExAllocateFromPagedLookasideList** returns a pointer to an entry if one can be allocated. Otherwise, it returns **NULL**.

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

If the given lookaside list is not empty, **ExAllocateFromPagedLookasideList** removes the first entry from the list and returns a pointer to this entry. Otherwise, **ExAllocateFromPagedLookasideList** either calls the *Allocate* routine specified at list initialization or [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) to return an entry pointer.

The caller can then set up the returned entry with any caller-determined data. The caller should release each entry with [ExFreeToPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetopagedlookasidelist) when it is no longer in use.

Because the entries in a paged lookaside list are allocated from pageable memory, they must not be accessed at an IRQL >= DISPATCH_LEVEL. You can use [ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist) to create a lookaside list with non-pageable entries.

On Windows 2000, drivers must use the **-D_WIN2K_COMPAT_SLIST_USAGE** switch to successfully link code that uses **ExAllocateFromPagedLookasideList**.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromnpagedlookasidelist)

[ExFreeToPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetopagedlookasidelist)

[ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)