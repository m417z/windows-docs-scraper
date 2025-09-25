# FltDeleteExtraCreateParameterLookasideList function

## Description

The **FltDeleteExtraCreateParameterLookasideList** routine frees an extra create parameter (ECP) lookaside list.

## Parameters

### `Filter` [in]

Opaque filter pointer to the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `Lookaside` [in, out]

Pointer to an opaque [PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) lookaside list-head structure that represents the lookaside list to be freed.

### `Flags` [in]

Communicates ECP lookaside list allocation options that were used when the lookaside list was initialized by the [FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist) routine.

This *Flags* parameter should be the same as the *Flags* parameter used in the call to the **FltInitExtraCreateParameterLookasideList** routine.

## Return value

None

## Remarks

This routine is available starting with Windows Vista.

The **FltDeleteExtraCreateParameterLookasideList** routine frees the given ECP lookaside list. However, freeing the lookaside list does not automatically free any ECP context structures allocated from the lookaside list. To free an ECP context structure allocated from a lookaside list, call the [FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine.

Drivers must explicitly free all ECP context structures and ECP lookaside lists that they created before unloading. For more information, see [Using Lookaside Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-lookaside-lists).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[FltAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[NPAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[PAGED_LOOKASIDE_LIST](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85))