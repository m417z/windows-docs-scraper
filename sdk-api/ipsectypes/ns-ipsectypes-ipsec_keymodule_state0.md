# IPSEC_KEYMODULE_STATE0 structure

## Description

The **IPSEC_KEYMODULE_STATE0** structure stores Internet Protocol Security (IPsec) keying module specific information.

## Members

### `keyModuleKey`

The identifier of the keying module.

### `stateBlob`

A byte blob containing opaque keying module specific information.

## Remarks

**IPSEC_KEYMODULE_STATE0** is a specific implementation of IPSEC_KEYMODULE_STATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)