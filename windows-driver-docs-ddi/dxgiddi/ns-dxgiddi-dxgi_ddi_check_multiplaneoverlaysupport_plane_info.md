# DXGI_DDI_CHECK_MULTIPLANEOVERLAYSUPPORT_PLANE_INFO structure

## Description

Specifies the support attributes that the hardware provides for multiplane overlays.

## Members

### `hResource`

A handle to the resource. The display miniport driver must set this member to a value that it can use to refer to its private tracking structure for the resource.

### `SubResourceIndex`

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or surface, on which an overlay plane is to be displayed.

### `PlaneAttributes`

A [DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_multiplane_overlay_attributes) structure that specifies overlay plane attributes.