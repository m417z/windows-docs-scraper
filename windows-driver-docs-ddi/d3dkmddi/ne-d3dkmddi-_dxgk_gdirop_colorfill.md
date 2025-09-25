# DXGK_GDIROP_COLORFILL enumeration

## Description

The **DXGK_GDIROP_COLORFILL** enumeration indicates the type of GDI raster operation (ROP) to implement in a GDI hardware-accelerated color fill operation.

## Constants

### `DXGK_GDIROPCF_INVALID:0`

Indicates that the GDI raster operation is invalid.

### `DXGK_GDIROPCF_PATCOPY:1`

Indicates that the specified color is copied into all pixels of the destination rectangle.

### `DXGK_GDIROPCF_PATINVERT:2`

Indicates that the specified color is combined with the colors of the destination rectangle by using the Boolean XOR operator.

### `DXGK_GDIROPCF_PDXN:3`

Indicates that the specified color is combined with the colors of the destination rectangle by using the Boolean NOT(XOR) operator.

### `DXGK_GDIROPCF_DSTINVERT:4`

Indicates that the destination rectangle is inverted.

### `DXGK_GDIROPCF_PATAND:5`

Indicates that the specified color is combined with the colors of the destination rectangle by using the Boolean AND operator.

### `DXGK_GDIROPCF_PATOR:6`

Indicates that the colors of the specified pattern are combined with the colors of the destination rectangle by using the Boolean OR operator.

### `DXGK_GDIROPCF_ROP3:7`

Indicates that a ternary GDI raster operation (ROP3) will be applied.