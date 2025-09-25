# _D3DDDIARG_CREATEOVERLAY structure

## Description

The D3DDDIARG_CREATEOVERLAY structure describes an overlay to create.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to overlay on (that is, the identifier of the primary surface to overlay on).

### `OverlayInfo` [in]

A pointer to the [D3DDDI_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfo) structure that describes information about the overlay.

### `hOverlay` [out]

A handle to the overlay. The user-mode display driver must set this handle to a value that the Microsoft Direct3D runtime can use to identify the overlay hardware in subsequent calls.

## See also

[CreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlay)

[D3DDDI_OVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlayinfo)