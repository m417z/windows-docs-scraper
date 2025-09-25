# FWPM_LAYER_STATISTICS0 structure

## Description

The **FWPM_LAYER_STATISTICS0** structure stores statistics related to a layer.

## Members

### `layerId`

Type: **GUID**

Identifier of the layer.

### `classifyPermitCount`

Type: **UINT32**

Number of permitted connections.

### `classifyBlockCount`

Type: **UINT32**

Number of blocked connections.

### `classifyVetoCount`

Type: **UINT32**

Number of vetoed connections.

### `numCacheEntries`

Type: **UINT32**

## Remarks

**FWPM_LAYER_STATISTICS0** is a specific implementation of FWPM_LAYER_STATISTICS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_statistics0)