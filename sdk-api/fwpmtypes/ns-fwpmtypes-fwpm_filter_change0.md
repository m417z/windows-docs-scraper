# FWPM_FILTER_CHANGE0 structure

## Description

The **FWPM_FILTER_CHANGE0** structure stores change notification dispatched to subscribers.

## Members

### `changeType`

A [FWPM_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_change_type) value that specifies the type of change notification to be dispatched.

### `filterKey`

GUID of the filter that changed.

### `filterId`

LUID of the filter that changed.

## Remarks

**FWPM_FILTER_CHANGE0** is a specific implementation of FWPM_FILTER_CHANGE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_change_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)