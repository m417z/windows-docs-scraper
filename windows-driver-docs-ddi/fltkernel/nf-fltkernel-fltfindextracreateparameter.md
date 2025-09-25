# FltFindExtraCreateParameter function

## Description

The **FltFindExtraCreateParameter** routine searches a given ECP list for an ECP context structure of a given type and returns a pointer to this structure if it is found.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpList` [in]

Pointer to the ECP list structure in which to search for the ECP context structure (given by the *EcpType* parameter).

### `EcpType` [in]

Pointer to a GUID that uniquely identifies each ECP context structure. This GUID value is used by the **FltFindExtraCreateParamter** routine to determine if the ECP context structure exists in the ECP list (given by the *EcpList* parameter).

### `EcpContext` [out, optional]

Optional parameter that receives a pointer to the found ECP context structure. If the ECP context structure is not found in the ECP list, *EcpContext* is set to **NULL**. If *EcpContext* is set to **NULL** by the caller, the return value of this routine can be used to determine if the ECP context structure is in the ECP list.

### `EcpContextSize` [out, optional]

Optional parameter that receives the size, in bytes, of the found ECP context structure. If the ECP context structure is not found in the ECP list, *EcpContextSize* is set to zero.

## Return value

**FltFindExtraCreateParameter** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The ECP context structure (as specified by the *EcpType* parameter) was found in the ECP list (as specified by the *EcpList* parameter). |
| **STATUS_NOT_FOUND** | The ECP context structure (as specified by the *EcpType* parameter) was not found in the ECP list (as specified by the *EcpList* parameter). |

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

**FltAllocateExtraCreateParameterFromLookasideList**

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)