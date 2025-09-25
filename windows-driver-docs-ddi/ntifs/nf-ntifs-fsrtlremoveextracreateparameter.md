# FsRtlRemoveExtraCreateParameter function

## Description

The **FsRtlRemoveExtraCreateParameter** routine searches an ECP list for an ECP context structure and, if found, detaches it from the ECP list.

## Parameters

### `EcpList` [in, out]

Pointer to the extra create parameter (ECP) list that contains the ECP context structure to be detached from the given list.

### `EcpType` [in]

Pointer to a GUID that uniquely identifies the ECP context structure to be detached from the list.

### `EcpContext` [out]

Pointer to the detached ECP context structure. If the ECP context structure is successfully detached from the given list, this parameter will be set to point to the detached ECP context structure. If the ECP context structure is not found in the given ECP list, this parameter is set to **NULL**.

### `EcpContextSize` [out, optional]

Optional parameter that receives the size of the detached ECP context structure. If this parameter is present when the routine is called, the parameter will receive the size, in bytes, of the detached ECP context structure. If the given ECP context structure was not found in the given ECP list, this parameter is undefined.

## Return value

**FsRtlRemoveExtraCreateParameter** returns an NTSTATUS code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The given ECP context structure was successfully detached from the given ECP list. |
| STATUS_NOT_FOUND | The given ECP context structure was not found in the given ECP list. |

## Remarks

The **FsRtlRemoveExtraCreateParameter** routine searches the ECP list given by the **EcpList** parameter for an ECP context structure given by the **EcpType** parameter. If the ECP context structure exists in the list, **FsRtlRemoveExtraCreateParameter** detaches the structure from the list, sets the **EcpContext** parameter to point to the structure, and returns STATUS_SUCCESS. If the ECP context structure does not exist in the list, **FsRtlRemoveExtraCreateParameter** sets the **EcpContext** parameter to **NULL** and returns STATUS_NOT_FOUND.

> [!NOTE]
> **FsRtlRemoveExtraCreateParameter** does not free the memory pool for the ECP context structure. To free the memory pool for the ECP context structure, first call **FsRtlRemoveExtraCreateParameter** to detach it from the list and then call the [**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine to free the memory pool for the ECP context structure.

## See also

[**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[**FsRtlAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter)

[**FsRtlAllocateExtraCreateParameterFromLookasideList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameterfromlookasidelist)

[**FltCreateFileEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[**FltGetEcpListFromCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[**FltInsertExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[**FltRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[**FltSetEcpListIntoCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)