# _DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE structure

> [!NOTE] This structure has been replaced by [DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane_with_source2).

## Description

**DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE**

Describes the multi-plane overlay plane attributes, allocation, and video present network source identification number.

## Members

### `hAllocation`

A handle to the allocation.

### `VidPnSourceId`

The zero-based video present network source identification number of the input for which the support levels are queried.

### `LayerIndex`

The index of the layer being queried.

### `PlaneAttributes`

A [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes2) structure that specifies overlay plane attributes.

## See also

[DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes2)