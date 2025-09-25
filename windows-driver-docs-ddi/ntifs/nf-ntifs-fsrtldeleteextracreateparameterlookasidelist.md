# FsRtlDeleteExtraCreateParameterLookasideList function

## Description

The **FsRtlDeleteExtraCreateParameterLookasideList** routine frees an extra create parameter (ECP) lookaside list.

## Parameters

### `Lookaside` [in, out]

Pointer to an opaque [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) lookaside list-head structure that represents the lookaside list to be freed.

### `Flags` [in]

Communicates ECP lookaside list allocation options with which the [FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist) routine initialized the lookaside list.

This *Flags* parameter should be the same as the *Flags* parameter used in the call to the [FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist) routine.

## Remarks

The **FsRtlDeleteExtraCreateParameterLookasideList** routine frees the ECP lookaside list to which the *Lookaside* parameter points. However, freeing the lookaside list does not automatically free any ECP context structures allocated from the lookaside list. To free an ECP context structure allocated from a lookaside list, call the [FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter) routine.

Drivers must explicitly free all ECP context structures and ECP lookaside lists that they created before unloading. For more information about using lookaside lists, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter)

[FsRtlInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinitextracreateparameterlookasidelist)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)