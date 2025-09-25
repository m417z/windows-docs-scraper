# FWPM_CALLOUT_ENUM_TEMPLATE0 structure

## Description

The **FWPM_CALLOUT_ENUM_TEMPLATE0** structure is used for limiting callout enumerations.

## Members

### `providerKey`

Uniquely identifies the provider associated with the callout. If this member is non-NULL, only objects associated with the specified provider will be returned.

### `layerKey`

Uniquely identifies a layer. If this member is non-NULL, only callouts associated with the specified layer will be returned.

## Remarks

**FWPM_CALLOUT_ENUM_TEMPLATE0** is a specific implementation of FWPM_CALLOUT_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)