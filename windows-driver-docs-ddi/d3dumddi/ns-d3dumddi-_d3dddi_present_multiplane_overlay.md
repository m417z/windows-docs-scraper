# _D3DDDI_PRESENT_MULTIPLANE_OVERLAY structure

## Description

Specifies an overlay plane to display.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates if the overlay plane specified by **LayerIndex** is enabled for display.

### `hResource`

A handle to the resource that is displayed by using the overlay plane.

### `SubResourceIndex`

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or surface, on which an overlay plane is to be displayed.

### `PlaneAttributes`

A [D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_multiplane_overlay_attributes) structure that specifies overlay plane attributes.

## See also

[D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_multiplane_overlay_attributes)