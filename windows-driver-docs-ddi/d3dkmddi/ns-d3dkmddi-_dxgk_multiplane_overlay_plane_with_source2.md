# _DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE2 structure

## Description

Used in a call to the *DxgkDdiCheckMultiPlaneOverlaySupport3* function to check details on hardware support for multi-plane overlays.

## Members

### `hAllocation`

A handle to the allocation.

### `VidPnSourceId`

The zero-based video present network (VidPN) source identification number of the input for which the support levels are queried.

### `LayerIndex`

The zero based index indicating the Z order of the overlay plane.

### `PlaneAttributes`

A [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3) structure that specifies overlay plane attributes.