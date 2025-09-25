# _DXGKARG_RECOMMENDVIDPNTOPOLOGY structure

## Description

The DXGKARG_RECOMMENDVIDPNTOPOLOGY structure contains arguments for the display miniport driver's [DxgkDdiRecommendVidPnTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendvidpntopology) function.

## Members

### `hVidPn`

A handle to a VidPN object. The *DxgkDdiRecommendVidPnTopology* function creates or augments the topology of this VidPN.

### `VidPnSourceId`

D3DDDI_ID_ALL or the identifier of a particular video present source on the display adapter. If this member is the identifier of a particular source, the *DxgkDdiRecommendVidPnTopology* function must augment the topology by adding at least one path that originates from that source. If this member is equal to D3DDDI_ID_ALL, *DxgkDdiRecommendVidPnTopology* must create the entire topology.

### `RequestReason`

 A value from the [DXGK_RECOMMENDVIDPNTOPOLOGY_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_recommendvidpntopology_reason) enumeration that indicates the reason that the [DxgkDdiRecommendVidPnTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendvidpntopology) function is being called.

### `hFallbackTopology`

A handle to a VidPN topology object that represents the fallback VidPN topology that Windows will use if the miniport does not provide a topology recommendation.

## See also

[DXGK_RECOMMENDVIDPNTOPOLOGY_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_recommendvidpntopology_reason)

[DxgkDdiRecommendVidPnTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendvidpntopology)