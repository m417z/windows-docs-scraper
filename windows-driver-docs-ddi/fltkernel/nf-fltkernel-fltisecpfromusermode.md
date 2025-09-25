# FltIsEcpFromUserMode function

## Description

The **FltIsEcpFromUserMode** routine is used to determine if an extra create parameter context structure (ECP) originated from user mode.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `EcpContext` [in]

Pointer to the ECP to test.

## Return value

The routine returns **TRUE** if the ECP originated in user mode and **FALSE** if the ECP originated in kernel mode.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FltAcknowledgeEcp](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacknowledgeecp)

[FltGetEcpListFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetecplistfromcallbackdata)

[FltInsertExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinsertextracreateparameter)

[FltRemoveExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveextracreateparameter)

[FltSetEcpListIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetecplistintocallbackdata)