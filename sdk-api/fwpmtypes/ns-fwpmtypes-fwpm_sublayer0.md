# FWPM_SUBLAYER0 structure

## Description

The **FWPM_SUBLAYER0** structure stores the state associated with a sublayer.

## Members

### `subLayerKey`

Uniquely identifies the sublayer. See [Filtering Sublayer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-sublayer-identifiers) for a list of built-in sublayers.

If the GUID is zero-initialized in the call to [FwpmSubLayerAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayeradd0), the Base Filtering Engine (BFE) will generate one.

### `displayData`

Allows sublayers to be annotated in human-readable form. The [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure is required.

### `flags`

Possible values:

| Sublayer flag | Meaning |
| --- | --- |
| **FWPM_SUBLAYER_FLAG_PERSISTENT** | Causes sublayer to be persistent, surviving across BFE stop/start. |

### `providerKey`

Uniquely identifies the provider that manages this sublayer.

### `providerData`

An [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that contains optional provider-specific data that allows providers to store additional context info with the object.

### `weight`

Weight of the sublayer.

Higher-weighted sublayers are invoked first.

## Remarks

**FWPM_SUBLAYER0** is a specific implementation of FWPM_SUBLAYER. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)