# ExAllocateFromLookasideListEx function

## Description

The **ExAllocateFromLookasideListEx** routine removes the first entry from the specified lookaside list, or, if the list is empty, dynamically allocates the storage for a new entry.

## Parameters

### `Lookaside` [in, out]

A pointer to a [LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes a lookaside list. This structure was previously initialized by the [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex) routine.

## Return value

**ExAllocateFromLookasideListEx** returns a pointer to a lookaside-list entry, if an entry is available in the list or can be dynamically allocated. Otherwise, this routine returns **NULL**.

## Remarks

> [!CAUTION]
> Starting in Windows 11, version 22H2, this function changed from inline to exported. As a result, if you build your driver targeting the latest version of Windows, it will fail to load in older OS versions. To change the target OS version in Visual Studio, select Configuration Properties->Driver Settings->General.

This routine removes the first entry, if an entry is available, from the specified lookaside list and returns a pointer to this entry. If the list is empty, the routine allocates storage for a new entry and returns a pointer to this entry. If this allocation fails, the routine returns **NULL**.

If the lookaside list is empty, **ExAllocateFromLookasideListEx** calls the [LookasideListAllocateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-allocate_function_ex) routine to allocate storage for a new entry, if the driver has provided such a routine. Otherwise, a default allocation routine is used to allocate the entry.

After the caller finishes using the entry, it should free the entry by calling the [ExFreeToLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetolookasidelistex) routine.

In the current implementation, a lookaside list operates as a last-in, first-out (LIFO) stack. Thus, the last entry to be freed (and pushed onto the stack) is the next entry to be allocated (popped) from the list.

For more information about lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExFreeToLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreetolookasidelistex)

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[LookasideListAllocateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-allocate_function_ex)