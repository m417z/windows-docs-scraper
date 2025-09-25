# FWPM_PROVIDER_CHANGE0 structure

## Description

The **FWPM_PROVIDER_CHANGE0** structure specifies a change notification dispatched to subscribers.

## Members

### `changeType`

Type of change.

See [FWPM_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_change_type) for more information.

### `providerKey`

GUID of the provider that changed.

## Remarks

**FWPM_PROVIDER_CHANGE0** is a specific implementation of FWPM_PROVIDER_CHANGE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_change_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)