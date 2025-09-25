# FWPM_CALLOUT_CHANGE_CALLBACK0 callback function

## Description

The **FWPM_CALLOUT_CHANGE_CALLBACK0** function is used to add custom behavior to the callout change notification process.

## Parameters

### `context` [in]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmCalloutSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutsubscribechanges0) function.

### `change` [in]

Type: [FWPM_CALLOUT_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_change0)*

The change notification information.

## Remarks

Call [FwpmCalloutSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutsubscribechanges0) to register this callback function.

**FWPM_CALLOUT_CHANGE_CALLBACK0** is a specific implementation of FWPM_CALLOUT_CHANGE_CALLBACK. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CALLOUT_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_change0)

[FwpmCalloutSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutsubscribechanges0)