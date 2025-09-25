# FltSetEcpListIntoCallbackData function

## Description

The **FltSetEcpListIntoCallbackData** routine attaches an extra create parameter context structure (ECP) list to a create operation callback-data object.

## Parameters

### `Filter` [in]

Opaque filter pointer to the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `CallbackData`

Pointer to a callback-data object of type [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data), which represents the create operation.

### `EcpList` [in]

Pointer to the ECP list, which contains one or more ECPs, to be attached to the callback-data object.

## Return value

**FltSetEcpListIntoCallbackData** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The given ECP list was successfully attached to the given callback-data object. |
| **STATUS_INVALID_PARAMETER_2** | The given callback data object was not an IRP-based create operation. |
| **STATUS_INVALID_PARAMETER_3** | An ECP list has already been attached to the given callback-data object. |

## Remarks

The **FltSetEcpListIntoCallbackData** routine provides a mechanism for passing extra create parameters down the file system filter stack to underlying minifilter and legacy filter drivers.

To retrieve an attached ECP list from a given callback-data object, use the [FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata) routine.

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

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltGetNextExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetnextextracreateparameter)

[FltInitExtraCreateParameterLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitextracreateparameterlookasidelist)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltIsEcpAcknowledged](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[FltIsEcpFromUserMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpfromusermode)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)