# D3DDDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO structure

## Description

Used to check multiplane overlay support plane info.

## Members

### `hResource`

A handle to the resource. The display miniport driver must set this member to a value that it can use to refer to its private tracking structure for the resource.

### `SubResourceIndex`

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or surface, on which an overlay plane is to be displayed.

### `PlaneAttributes`

A [D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_multiplane_overlay_attributes) structure that specifies overlay plane attributes.

## Remarks

## See also