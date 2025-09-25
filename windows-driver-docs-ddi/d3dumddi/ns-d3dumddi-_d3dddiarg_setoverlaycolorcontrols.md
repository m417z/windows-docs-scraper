# _D3DDDIARG_SETOVERLAYCOLORCONTROLS structure

## Description

The D3DDDIARG_SETOVERLAYCOLORCONTROLS structure describes the parameters for changing an overlay's color-control settings.

## Members

### `hOverlay` [in]

A handle to the overlay that [SetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setoverlaycolorcontrols) changes color-control settings for.

### `hResource` [in]

A handle to the resource that is associated with the overlay that **hOverlay** specifies.

### `ColorControls` [in]

A [D3DDDI_OVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrols) structure that contains color-control settings.

## See also

[D3DDDI_OVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_overlaycolorcontrols)

[SetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setoverlaycolorcontrols)