# ExDeletePagedLookasideList function

## Description

The **ExDeletePagedLookasideList** routine destroys a paged lookaside list.

## Parameters

### `Lookaside` [in, out]

A pointer to the [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the lookaside list, which the caller already initialized with [ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist), which the caller originally set up with **ExInitializePagedLookasideList**.

## Remarks

**ExDeletePagedLookasideList** is the reciprocal of **ExInitializePagedLookasideList**. It frees any remaining entries in the specified lookaside list and then removes the list from the system-wide set of active lookaside lists.

The caller of **ExDeletePagedLookasideList** is responsible for subsequently releasing the memory that the caller provided to contain the list head.

For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ExInitializePagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepagedlookasidelist)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)