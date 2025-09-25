# FltInsertExtraCreateParameter function

## Description

The **FltInsertExtraCreateParameter** routine inserts an extra create parameter (ECP) context structure into an ECP list.

## Parameters

### `Filter` [in]

Opaque filter pointer to the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpList` [in, out]

Pointer to the ECP list structure to which the ECP context structure, provided by the *EcpContext* parameter, should be added.

### `EcpContext` [in, out]

Pointer to the ECP context structure to be added to the ECP list, provided by the *EcpList* parameter.

## Return value

**FltInsertExtraCreateParameter** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The given ECP context structure was successfully inserted into the given ECP list. |
| **STATUS_INVALID_PARAMETER** | The given ECP context structure already exists in the given ECP list. In the context of ECP list insertion, two ECP context structures are considered to be identical if they contain equal GUID values. |

## Remarks

The **FltInsertExtraCreateParameter** routine assumes that the given ECP context structure to be inserted into the given ECP list was previously allocated by the [FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) routine.

Each ECP context structure inserted into the ECP list must have a unique GUID value. This unique value is set when the ECP context structure is allocated by the [FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) routine.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter)

[FltAllocateExtraCreateParameterFromLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)