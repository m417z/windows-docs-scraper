# FsRtlAcknowledgeEcp function

## Description

The **FsRtlAcknowledgeEcp** routine marks an extra create parameter (ECP) context structure as acknowledged.

## Parameters

### `EcpContext` [in]

A pointer to the ECP to mark as acknowledged.

## Remarks

When **FsRtlAcknowledgeEcp** marks an ECP as acknowledged, it could indicate whether the ECP has been looked at, used, processed, or any other condition of the ECP.

You can use the [**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged) routine to determine if a particular ECP has been marked as acknowledged.

## See also

[**ECP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters)

[**FltAllocateExtraCreateParameterFromLookasideList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterfromlookasidelist)

[**FltFreeExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameter)

[**FltGetEcpListFromCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[**FltIsEcpFromUserMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpfromusermode)

[**FltRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[**FltSetEcpListIntoCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)