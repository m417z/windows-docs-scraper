# FsRtlFindExtraCreateParameter function

## Description

The **FsRtlFindExtraCreateParameter** routine searches a given ECP list for an ECP context structure of a given type and returns a pointer to this structure if it is found.

## Parameters

### `EcpList` [in]

Pointer to the ECP list structure that **FsRtlFindExtraCreateParameter** uses to search for the ECP context structure, supplied by the *EcpType* parameter.

### `EcpType` [in]

Pointer to a GUID that uniquely identifies the ECP context structure. This GUID value is used by the **FsRtlFindExtraCreateParamter** routine to determine if the ECP context structure exists in the ECP list, supplied by the *EcpList* parameter.

### `EcpContext` [out, optional]

Optional parameter that receives a pointer to the found ECP context structure. If the ECP context structure is not found in the ECP list, *EcpContext* is set to **NULL**. If *EcpContext* is set to **NULL** by the caller, the return value of **FsRtlFindExtraCreateParamter** can be used to determine if the ECP context structure is in the ECP list.

### `EcpContextSize` [out, optional]

Optional parameter that receives the size, in bytes, of the found ECP context structure. If the ECP context structure is not found, *EcpContextSize* is set to zero.

## Return value

**FsRtlFindExtraCreateParameter** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | **FsRtlFindExtraCreateParameter** found the specified ECP context structure in the specified ECP list. |
| **STATUS_NOT_FOUND** | **FsRtlFindExtraCreateParameter** didn't find the specified ECP context structure in the specified ECP list. |

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