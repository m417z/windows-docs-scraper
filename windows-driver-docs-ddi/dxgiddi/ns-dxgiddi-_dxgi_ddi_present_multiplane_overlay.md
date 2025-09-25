# _DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY structure

## Description

Specifies overlay planes to display.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates whether the overlay plane specified by **LayerIndex** is enabled for display.

### `hResource`

A handle to the resource that is displayed by using the overlay plane.

### `SubResourceIndex`

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or surface, on which an overlay plane is to be displayed.

### `PlaneAttributes`

A structure of type [DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_multiplane_overlay_attributes) that specifies overlay plane attributes.

## See also

[DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_multiplane_overlay_attributes)