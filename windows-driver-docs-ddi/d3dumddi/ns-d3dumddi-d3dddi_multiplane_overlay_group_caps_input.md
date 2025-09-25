# D3DDDI_MULTIPLANE_OVERLAY_GROUP_CAPS_INPUT structure

## Description

Specifies info on a multiplane overlay capability group.

## Members

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the capabilities are queried.

### `GroupIndex` [in]

The index of the overlay capability group for which capabilities are queried. This value is always between zero and ([D3DDDI_MULTIPLANE_OVERLAY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_caps).**NumCapabilityGroups** – 1).

## See also

[D3DDDI_MULTIPLANE_OVERLAY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_caps)