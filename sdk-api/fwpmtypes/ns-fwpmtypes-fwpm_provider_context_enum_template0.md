# FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0 structure

## Description

The **FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0** structure is used for enumerating provider contexts.

## Members

### `providerKey`

Uniquely identifies a provider. If this value is non-NULL, only options with the specifies provider will be returned.

### `providerContextType`

Only return provider contexts of the specified type.

See [FWPM_PROVIDER_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type) for more information.

## Remarks

**FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0** is a specific implementation of FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_PROVIDER_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)