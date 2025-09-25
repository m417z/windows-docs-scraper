# FWPM_PROVIDER_CONTEXT_CHANGE_CALLBACK0 callback function

## Description

The **FWPM_PROVIDER_CONTEXT_CHANGE_CALLBACK0** function is used to add custom behavior to the provider context change notification process.

## Parameters

### `context` [in]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter passed to the [FwpmProviderContextSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextsubscribechanges0) function.

### `change` [in]

Type: [FWPM_PROVIDER_CONTEXT_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_change0)*

The change notification information.

## Remarks

Call [FwpmProviderContextSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextsubscribechanges0) to register this callback function.

**FWPM_PROVIDER_CONTEXT_CHANGE_CALLBACK0** is a specific implementation of FWPM_PROVIDER_CONTEXT_CHANGE_CALLBACK. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_PROVIDER_CONTEXT_CHANGE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_change0)

[FwpmProviderContextSubscribeChanges0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextsubscribechanges0)