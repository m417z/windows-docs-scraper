# FltRemoveExtraCreateParameter function

## Description

The **FltRemoveExtraCreateParameter** routine searches an ECP list for an ECP context structure and, if found, detaches it from the ECP list.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpList` [in, out]

Pointer to the extra create parameter (ECP) list that contains the ECP context structure to be detached from the given list.

### `EcpType` [in]

Pointer to a user-defined GUID that uniquely identifies the ECP context structure to be detached from the list.

### `EcpContext` [out]

Pointer to the detached ECP context structure. If the ECP context structure is successfully detached from the given list, this parameter will be set to point to the detached ECP context structure. If the ECP context structure is not found in the given ECP list, this parameter is set to **NULL**.

### `EcpContextSize` [out, optional]

Optional parameter that receives the size of the detached ECP context structure. If this parameter is present when the routine is called, the parameter will receive the size, in bytes, of the detached ECP context structure. If the given ECP context structure was not found in the given ECP list, this parameter is undefined.

## Return value

**FltRemoveExtraCreateParameter** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The given ECP context structure was successfully detached from the given ECP list. |
| **STATUS_NOT_FOUND** | The given ECP context structure was not found in the given ECP list. |

## Remarks

The **FltRemoveExtraCreateParameter** routine searches the ECP list given by the *EcpList* parameter for an ECP context structure given by the *EcpType* parameter. If the ECP context structure exists in the list, it is detached from the list, the *EcpContext* parameter is set to point to it, and the routine returns STATUS_SUCCESS. If the ECP context structure does not exist in the list, the *EcpContext* parameter is set to **NULL** and the routine returns STATUS_NOT_FOUND.

**Note** This routine does not free the memory pool for the ECP context structure. To free the ECP context structure, first call this routine to detach it from the list and then call the [FltFreeExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter) routine to free the ECP context structure itself.

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