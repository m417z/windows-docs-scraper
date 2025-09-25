# _DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO structure

## Description

Specifies an overlay plane to display during a VSync interval.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates if the overlay plane specified by **LayerIndex** is enabled for display.

### `PhysicalAddress` [in]

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address within the segment where the data is read.

### `PlaneAttributes`

A structure of type [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes) that specifies overlay plane attributes.