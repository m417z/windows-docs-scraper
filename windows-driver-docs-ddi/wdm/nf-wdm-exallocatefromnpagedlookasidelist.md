# ExAllocateFromNPagedLookasideList function

## Description

The **ExAllocateFromNPagedLookasideList** routine returns a pointer to a nonpaged entry from the given lookaside list, or it returns a pointer to a newly allocated nonpaged entry.

## Parameters

### `Lookaside` [in, out]

A pointer to the [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller already initialized with [ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist).

## Return value

**ExAllocateFromNPagedLookasideList** returns a pointer to an entry if one can be allocated. Otherwise, it returns **NULL**.

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

If the given lookaside list is not empty, **ExAllocateFromNPagedLookasideList** removes the first entry from the list and returns a pointer to this entry. Otherwise, **ExAllocateFromNPagedLookasideList** either calls the *Allocate* routine specified at list initialization or [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) to return an entry pointer.

The caller can then set up the returned entry with any caller-determined data. For example, a driver might use each such fixed-size entry to set up command blocks, like SCSI SRBs, to peripheral devices on a particular type of I/O bus. The caller should release each entry with [ExFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetonpagedlookasidelist) when it is no longer in use.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExAllocateFromPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefrompagedlookasidelist)

[ExFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetonpagedlookasidelist)

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)