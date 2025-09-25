# FsRtlPrepareToReuseEcp function

## Description

The **FsRtlPrepareToReuseEcp** routine resets an extra create parameter (ECP) context structure, which prepares it for reuse.

## Parameters

### `EcpContext` [in]

A pointer to the ECP to prepare for reuse.

## Remarks

The **FsRtlPrepareToReuseEcp** allows reuse of an ECP used in a previous create request. This prevents having to initialize a new ECP with the same information.

The target of an ECP uses [**FsRtlAcknowledgeEcp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlacknowledgeecp) to mark the ECP as acknowledged. This indicates that the ECP was discovered and processed. To reuse a previously acknowledged ECP, such as in processing a reparse, a driver can use **FsRtlPrepareToReuseEcp** to clear the acknowledged state from the ECP before sending it in another create request.

Within a file system minifilter driver, use [**FltPrepareToReuseEcp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparetoreuseecp) to reuse an ECP.

## See also

[**ECP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters)

[**FltPrepareToReuseEcp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparetoreuseecp)

[**FsRtlInsertExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertextracreateparameter)

[**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter)