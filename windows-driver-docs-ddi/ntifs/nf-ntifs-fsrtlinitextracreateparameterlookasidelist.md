# FsRtlInitExtraCreateParameterLookasideList function

## Description

The **FsRtlInitExtraCreateParameterLookasideList** routine initializes a paged or nonpaged pool lookaside list used for the allocation of one or more extra create parameter context structures (ECPs) of fixed size.

## Parameters

### `Lookaside` [in, out]

Pointer to an opaque [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) lookaside list-head structure. For a paged or nonpaged lookaside list, the list-head structure must be allocated from nonpaged pool.

### `Flags` [in]

Defines pool allocation options. If the *Flags* parameter contains the FSRTL_ECP_LOOKASIDE_FLAG_NONPAGED_POOL bit flag value, **FsRtlInitExtraCreateParameterLookasideList** initializes a lookaside list for nonpaged ECP entries of the specified size. Otherwise, **FsRtlInitExtraCreateParameterLookasideList** initializes a lookaside list for paged ECP entries of the specified size.

### `Size` [in]

Specifies the size, in bytes, for all ECP entries in the lookaside list.

### `Tag` [in]

Specifies the pool tag to use when allocating lookaside list ECP entries. For more information about pool tags, see the *Tag* parameter of [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Remarks

Use this routine to initialize a paged or nonpaged pool lookaside list. Use the [FsRtlAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameterfromlookasidelist) routine to allocate an ECP from the lookaside list, and the [FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter) routine to return an ECP buffer to the lookaside list for recycling.

Use the [FsRtlDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtldeleteextracreateparameterlookasidelist) routine to free the lookaside list itself.

Drivers must free all ECPs and lookaside lists that they create before they unload.

For more information on using lookaside lists with drivers, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[FsRtlAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameterfromlookasidelist)

[FsRtlDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtldeleteextracreateparameterlookasidelist)

[FsRtlFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeextracreateparameter)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)