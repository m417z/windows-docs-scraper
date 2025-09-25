# FwpsCompleteClassify0 function

## Description

A callout driver calls **FwpsCompleteClassify0** to asynchronously complete a pended classify request. The callout driver's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function must have previously called [FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0) to pend the classify request.

> [!Note]
> **FwpsCompleteClassify0** is a specific version of **FwpsCompleteClassify**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyHandle` [in]

The classification handle that identifies the callout driver's processing at the current layer. This handle is obtained by calling [FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

### `flags` [in]

This parameter is reserved for future use. Set to zero.

### `classifyOut` [in, optional]

A pointer to a deep copy of the [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure that was originally passed to the [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) call when the classification was pended. When classifying asynchronously, the members of this structure can be set the same way as they would be in the callout driver's *classifyFn* function when classifying inline.

If this parameter is used, the classification is taken as the callout driver's final decision. If set to **NULL**, the indication will be reauthorized.

## Remarks

**FwpsCompleteClassify0** must be called after a callout driver has called [FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0) to remove the classification from its pended state.

After calling this function, [FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0) must be called to free the system resources associated with the classification handle.

## See also

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0)

[FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0)

[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)