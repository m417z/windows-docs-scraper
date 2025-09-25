# ExFlushLookasideListEx function

## Description

The **ExFlushLookasideListEx** routine flushes all entries from the specified lookaside list and frees the allocated storage for each entry.

## Parameters

### `Lookaside` [in, out]

A pointer to a [LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes a lookaside list. This structure was previously initialized by the [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex) routine.

## Remarks

On return from this routine, the lookaside list is empty and the allocated storage for all its entries has been freed.

For more information about lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)