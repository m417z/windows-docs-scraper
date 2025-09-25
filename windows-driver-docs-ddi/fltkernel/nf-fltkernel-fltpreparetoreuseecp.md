# FltPrepareToReuseEcp function

## Description

The **FltPrepareToReuseEcp** routine resets an extra create parameter (ECP) context structure, which prepares it for reuse.

## Parameters

### `Filter` [in]

An opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpContext` [in]

A pointer to the ECP to prepare for reuse.

## Return value

None.

## Remarks

The **FltPrepareToReuseEcp** allows reuse of an ECP used in a previous create request. This prevents having to initialize a new ECP with the same information.

The target of an ECP uses [FltAcknowledgeEcp](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacknowledgeecp) to mark the ECP as acknowledged. This indicates that the ECP was discovered and processed. To reuse a previously acknowledged ECP, such as in processing a reparse, a driver can use **FltPrepareToReuseEcp** to clear the acknowledged state from the ECP before sending it in another create request.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltIsEcpAcknowledged](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)

[FltlInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)