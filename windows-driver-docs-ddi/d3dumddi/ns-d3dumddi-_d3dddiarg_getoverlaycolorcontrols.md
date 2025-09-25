# _D3DDDIARG_GETOVERLAYCOLORCONTROLS structure

## Description

The D3DDDIARG_GETOVERLAYCOLORCONTROLS structure describes the parameters for retrieving an overlay's color-control settings.

## Members

### `hOverlay` [in]

A handle to the overlay that [GetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getoverlaycolorcontrols) retrieves color-control settings for.

### `hResource` [in]

A handle to the resource that is associated with the overlay that **hOverlay** specifies.

### `ColorControls` [out]

A [D3DDDI_OVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrols) structure that [GetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getoverlaycolorcontrols) populates with color-control settings.

## See also

[D3DDDI_OVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrols)

[GetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getoverlaycolorcontrols)