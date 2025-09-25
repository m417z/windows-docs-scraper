# _DXGK_MULTIPLANE_OVERLAY_PLANE2 structure

> [!NOTE] This structure has been replaced by [DXGK_MULTIPLANE_OVERLAY_PLANE3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane3).

## Description

**DXGK_MULTIPLANE_OVERLAY_PLANE2** is used with the [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay2) function to specify an overlay plane to display.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates whether the overlay plane specified by **LayerIndex** is enabled for display.

### `AllocationSegment`

The identifier of a segment that data is read from.

### `AllocationAddress`

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address within the segment that **AllocationSegment** specifies, where the data is read.

### `hAllocation`

A handle to the allocation to be displayed on the overlay plane.

### `PlaneAttributes`

A structure of type [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes2) that specifies overlay plane attributes.

## See also

[DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes2)

[DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay2)