# FltFreeExtraCreateParameter function

## Description

The **FltFreeExtraCreateParameter** routine frees the memory for an ECP context structure.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpContext` [in]

Pointer to the extra create parameter (ECP) context structure to be freed.

## Return value

None.

## Remarks

If the ECP context structure to be freed is still attached to an ECP list, it must first be detached from the list by the [FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter) routine before the **FltFreeExtraCreateParameter** routine can be called to free it.

If a cleanup callback routine of type PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK was defined for the given ECP context structure, this callback routine is invoked upon deletion of the ECP context structure. For more information, see [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85)).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[FltAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85))