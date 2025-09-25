# _DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_WITH_SOURCE structure

## Description

Used in a call to the [DxgkDdiCheckMultiPlaneOverlaySupport3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3) function to check details on hardware support for post composition transform support.

## Members

### `VidPnSourceId`

The zero-based video present network (VidPN) source identification number of the input for which the support levels are queried.

### `PostComposition`

A DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION structure that specifies additional transforms that should be applied after the planes are composed.