# FWPS_DISCARD_MODULE0 enumeration

## Description

The **FWPS_DISCARD_MODULE0** enumeration type specifies the type of module that discarded the
data.

**Note** **FWPS_DISCARD_MODULE0** is a specific version of **FWPS_DISCARD_MODULE**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Constants

### `FWPS_DISCARD_MODULE_NETWORK:0`

The data was discarded by the network layer.

### `FWPS_DISCARD_MODULE_TRANSPORT`

The data was discarded by the transport layer.

### `FWPS_DISCARD_MODULE_GENERAL`

The data was discarded by the filter engine.

### `FWPS_DISCARD_MODULE_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The
[FWPS_DISCARD_METADATA0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_discard_metadata0) structure
contains a member of type FWPS_DISCARD_MODULE0 that specifies the type of module that discarded the
data.

## See also

[FWPS_DISCARD_METADATA0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_discard_metadata0)