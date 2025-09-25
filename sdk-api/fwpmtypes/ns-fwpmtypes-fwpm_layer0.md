# FWPM_LAYER0 structure

## Description

The **FWPM_LAYER0** structure contains schema information for a layer.

## Members

### `layerKey`

Uniquely identifies the layer.

### `displayData`

Allows layers to be annotated in a human-readable form. The [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure is not **NULL**.

### `flags`

Possible values:

| Value | Meaning |
| --- | --- |
| **FWPM_LAYER_FLAG_KERNEL** | Layer classified in kernel-mode. |
| **FWPM_LAYER_FLAG_BUILTIN** | Layer built-in. Cannot be deleted. |
| **FWPM_LAYER_FLAG_CLASSIFY_MOSTLY** | Layer optimized for classification rather than enumeration. |
| **FWPM_LAYER_FLAG_BUFFERED** | Layer is buffered. |

### `numFields`

Number of fields in the layer.

### `field`

Schema information for the layer's fields.

See [FWPM_FIELD0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_field0) for more information.

### `defaultSubLayerKey`

Sublayer used when a filter is added with a null sublayer.

### `layerId`

LUID that identifies this layer.

## Remarks

**FWPM_LAYER0** is a specific implementation of FWPM_LAYER. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[FWPM_FIELD0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_field0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)