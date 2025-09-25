# DXGK_RENDERKM_OPERATION enumeration

## Description

The **DXGK_RENDERKM_OPERATION** enumeration indicates the type of GDI hardware-accelerated rendering operation to perform when the [**DxgkDdiRenderKm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function is called.

## Constants

### `DXGK_GDIOP_BITBLT:1`

Indicates a bit-block transfer (bitblt).

### `DXGK_GDIOP_COLORFILL:2`

Indicates a color fill.

### `DXGK_GDIOP_ALPHABLEND:3`

Indicates an alpha blend.

### `DXGK_GDIOP_STRETCHBLT:4`

Indicates a stretch blt.

### `DXGK_GDIOP_ESCAPE:5`

Reserved for future use. The driver should skip this command when setting the value of the **CommandSize** member of the [**DXGK_RENDERKM_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command) structure.

### `DXGK_GDIOP_TRANSPARENTBLT:6`

Indicates a blt with transparency.

### `DXGK_GDIOP_CLEARTYPEBLEND:7`

Indicates a ClearType blend.

## See also

[**DXGK_RENDERKM_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command)

[**DxgkDdiRenderKm**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm)