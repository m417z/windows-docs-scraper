# FltGetEcpListFromCallbackData function

## Description

The **FltGetEcpListFromCallbackData** routine returns a pointer to an extra create parameter context structure (ECP) list that is associated with a given create operation callback-data object.

## Parameters

### `Filter` [in]

An opaque filter pointer to the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `CallbackData`

A pointer to a callback-data object of type [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data), which represents the create operation.

### `EcpList` [out]

Receives a pointer to the ECP list that is associated with the *CallbackData* callback-data object.

## Return value

**FltGetEcpListFromCallbackData** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | *EcpList* received a pointer to the ECP list that is associated with the given callback-data object. If the callback-data object has no associated ECP, STATUS_SUCCESS is returned and *EcpList* is **NULL**. |
| **STATUS_INVALID_PARAMETER** | The given callback-data object was not an IRP-based create operation. In this case, *EcpList* is undefined. |

## Remarks

To attach an ECP list to a callback-data object, use the [FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata) routine.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltAcknowledgeEcp](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacknowledgeecp)

[FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[FltAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltDeleteExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteextracreateparameterlookasidelist)

[FltFindExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfindextracreateparameter)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[FltGetNextExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetnextextracreateparameter)

[FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltIsEcpAcknowledged](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[FltIsEcpFromUserMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpfromusermode)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)