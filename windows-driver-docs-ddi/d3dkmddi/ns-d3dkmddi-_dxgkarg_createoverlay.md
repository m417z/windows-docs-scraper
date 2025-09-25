# _DXGKARG_CREATEOVERLAY structure

## Description

The DXGKARG_CREATEOVERLAY structure describes parameters to create an overlay.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the overlay is displayed on.

### `OverlayInfo` [in]

A [DXGK_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_overlayinfo) structure that contains parameters that are required to create the overlay.

### `hOverlay` [out]

A handle to the newly created overlay.

## See also

[DXGK_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_overlayinfo)

[DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay)