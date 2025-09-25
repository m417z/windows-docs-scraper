# ExDeleteLookasideListEx function

## Description

The **ExDeleteLookasideListEx** routine deletes a lookaside list.

## Parameters

### `Lookaside` [in, out]

A pointer to a [LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that describes a lookaside list. This structure was previously initialized by the [ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex) routine.

## Remarks

**ExDeleteLookasideListEx** is the reciprocal of the **ExInitializeLookasideListEx** routine. It frees any remaining entries in the specified lookaside list and then removes the list from the system-wide set of active lookaside lists.

On return from **ExDeleteLookasideListEx**, the caller is responsible for releasing, if necessary, the caller-supplied storage for the **LOOKASIDE_LIST_EX** structure.

For more information about lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExInitializeLookasideListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializelookasidelistex)

[LOOKASIDE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)