# ExFreeToLookasideListEx function

## Description

The **ExFreeToLookasideListEx** routine inserts an entry into a lookaside list, or, if the list is full, frees the allocated storage for the entry.

## Parameters

### `Lookaside` [in, out]

A pointer to a [LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes a lookaside list. This structure was previously initialized by the [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex) routine.

### `Entry` [in]

A pointer to the lookaside-list entry that is being freed.

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

This routine frees a lookaside-list entry that was allocated by a previous call to the [ExAllocateFromLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromlookasidelistex) routine. **ExFreeToLookasideListEx** inserts the entry into the specified lookaside list, if space for the entry is available in the list. If the list is full (that is, it already contains the maximum number of entries, as determined by the operating system), **ExFreeToLookasideListEx** calls the [LookasideListFreeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-free_function_ex) routine to free the storage for the specified entry, if the driver has provided such a routine. Otherwise, a default deallocation routine is used to free the entry.

For more information about lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExAllocateFromLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatefromlookasidelistex)

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)