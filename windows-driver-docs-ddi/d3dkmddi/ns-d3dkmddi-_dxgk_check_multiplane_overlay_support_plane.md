# _DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE structure

## Description

Specifies the support attributes that the hardware provides for multiplane overlays.

## Members

### `hAllocation` [out]

A handle to the allocation. The display miniport driver must set this member to a value that it can use to refer to its private tracking structure for the allocation.

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the support levels are queried.

### `PlaneAttributes`

A [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes) structure that specifies overlay plane attributes.

## See also

[DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes)