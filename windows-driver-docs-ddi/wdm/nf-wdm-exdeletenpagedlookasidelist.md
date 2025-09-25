# ExDeleteNPagedLookasideList function

## Description

The **ExDeleteNPagedLookasideList** routine destroys a nonpaged lookaside list.

## Parameters

### `Lookaside` [in, out]

A pointer to the [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller originally set up with [ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist).

## Remarks

**ExDeleteNPagedLookasideList** is the reciprocal of **ExInitializeNPagedLookasideList**. It frees any remaining entries in the specified lookaside list and then removes the list from the system-wide set of active lookaside lists.

The caller of **ExDeleteNPagedLookasideList** is responsible for subsequently releasing the memory that the caller provided to contain the list head.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializenpagedlookasidelist)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)