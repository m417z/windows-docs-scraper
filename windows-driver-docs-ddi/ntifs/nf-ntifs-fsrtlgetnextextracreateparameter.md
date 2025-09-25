# FsRtlGetNextExtraCreateParameter function

## Description

The **FsRtlGetNextExtraCreateParameter** routine returns a pointer to the next (or first) extra create parameter (ECP) context structure in a given ECP list.

## Parameters

### `EcpList` [in]

Pointer to the ECP list to examine.

### `CurrentEcpContext` [in, optional]

Optional pointer to an ECP context structure in the given ECP list. If present, **FsRtlGetNextExtraCreateParameter** returns a pointer to the ECP after the *CurrentEcpContext* ECP context structure. If *CurrentEcpContext* is **NULL**, **FsRtlGetNextExtraCreateParameter** returns the first ECP context structure in the list.

### `NextEcpType` [out, optional]

Optional parameter that receives a pointer to the GUID of the returned ECP context structure.

### `NextEcpContext` [out]

Optional parameter that receives a pointer to the returned ECP context structure.

### `NextEcpContextSize` [out, optional]

Optional parameter that receives the size, in bytes, of the returned ECP context structure.

## Return value

**FsRtlGetNextExtraCreateParameter** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | **FsRtlGetNextExtraCreateParameter** found an ECP context structure in the *EcpList* ECP list. |
| **STATUS_NOT_FOUND** | The *EcpList* ECP list is empty or *CurrentEcpContext* is the last ECP in the list (that is, there is no next ECP list element). Additionally, *NextEcpContext* is set to **NULL** and *NextEcpContextSize* is set to zero. |
| **STATUS_INVALID_PARAMETER** | The *EcpList* parameter is **NULL**. |

## Remarks

The**FsRtlGetNextExtraCreateParameter** routine processes an ECP list in a non-circular manner. That is, if the ECP context structure pointed to by the *CurrentEcpContext* parameter is the last element in the ECP list, there is no "next" ECP in the list and the routine returns STATUS_NOT_FOUND.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

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