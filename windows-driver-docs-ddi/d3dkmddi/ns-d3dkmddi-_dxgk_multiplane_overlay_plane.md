# _DXGK_MULTIPLANE_OVERLAY_PLANE structure

> [!NOTE] This structure has been replaced by [DXGK_MULTIPLANE_OVERLAY_PLANE3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane3).

## Description

Specifies an overlay plane to display in a call to the [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay) function.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates whether the overlay plane specified by **LayerIndex** is enabled for display.

If **FALSE**, the display miniport driver should disable the specified overlay plane.

If a plane was enabled during a previous call to [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay), the driver should continue to display the plane without flipping it.

### `AllocationSegment` [in]

The identifier of a segment that data is read from.

### `AllocationAddress` [in]

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address, within the segment that **AllocationSegment** specifies, where the data is read.

### `hAllocation`

A handle to the allocation to be displayed on the overlay plane.

### `PlaneAttributes`

A structure of type [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes) that specifies overlay plane attributes.

## See also

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay)