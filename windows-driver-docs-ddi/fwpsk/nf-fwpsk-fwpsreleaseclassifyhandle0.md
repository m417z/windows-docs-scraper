# FwpsReleaseClassifyHandle0 function

## Description

A callout driver calls
**FwpsReleaseClassifyHandle0** to release a classification handle that was previously acquired through a
call to
[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

**Note** **FwpsReleaseClassifyHandle0** is a specific version of **FwpsReleaseClassifyHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyHandle` [in]

The classification handle that identifies the callout driver's processing at the current layer.
This handle is obtained by calling
[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

## Remarks

Any time
[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0) is
called, a corresponding call to
**FwpsReleaseClassifyHandle0** must be made to free the system resources associated with the
classification handle.

## See also

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0)

[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0)

[FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)