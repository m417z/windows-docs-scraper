# FWPM_SUBLAYER_CHANGE_CALLBACK0 callback function

## Description

The **FWPM_SUBLAYER_CHANGE_CALLBACK0** function is used to added custom behavior to the sublayer change notification process.

## Parameters

### `context` [in]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmSubLayerSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayersubscribechanges0) function.

### `change` [in]

Type: [FWPM_SUBLAYER_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer_change0)*

The change notification information.

## Remarks

Call [FwpmSubLayerSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayersubscribechanges0) to register this callback function.

**FWPM_SUBLAYER_CHANGE_CALLBACK0** is a specific implementation of FWPM_SUBLAYER_CHANGE_CALLBACK. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SUBLAYER_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer_change0)

[FwpmSubLayerSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayersubscribechanges0)