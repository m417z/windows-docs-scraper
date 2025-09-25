# DXGK_GDIROP_BITBLT enumeration

## Description

The **DXGK_GDIROP_COLORFILL** enumeration indicates the type of GDI raster operation (ROP) to implement in a GDI hardware-accelerated bit-block transfer (bitblt) operation.

## Constants

### `DXGK_GDIROP_INVALID:0`

Indicates that the GDI raster operation is invalid.

### `DXGK_GDIROP_SRCCOPY:1`

Indicates that the source rectangle is copied to the destination rectangle.

### `DXGK_GDIROP_SRCINVERT:2`

Indicates that the color of each pixel of the source rectangle is combined with the color of the respective pixel of the destination rectangle by using the Boolean XOR operator.

### `DXGK_GDIROP_SRCAND:3`

Indicates that the color of each pixel of the source rectangle is combined with the color of the respective pixel of the destination rectangle by using the Boolean AND operator.

### `DXGK_GDIROP_SRCOR:4`

Indicates that the color of each pixel of the source rectangle is combined with the color of the respective pixel of the destination rectangle by using the Boolean OR operator.

### `DXGK_GDIROP_ROP3:5`

Indicates that a ternary GDI raster operation (ROP3) will be applied.

## See also

[**DXGK_GDIARG_BITBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_bitblt)