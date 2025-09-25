# EMRBITBLT structure

## Description

The **EMRBITBLT** structure contains members for the [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) enhanced metafile record. Note that graphics device interface (GDI) converts the device-dependent bitmap into a device-independent bitmap (DIB) before storing it in the metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `xDest`

Logical x-coordinate of the upper-left corner of the destination rectangle.

### `yDest`

Logical y-coordinate of the upper-left corner of the destination rectangle.

### `cxDest`

Logical width of the destination rectangle.

### `cyDest`

Logical height of the destination rectangle.

### `dwRop`

Raster-operation code. These codes define how the color data of the source rectangle is to be combined with the color data of the destination rectangle to achieve the final color.

### `xSrc`

Logical x-coordinate of the upper-left corner of the source rectangle.

### `ySrc`

Logical y-coordinate of the upper-left corner of the source rectangle.

### `xformSrc`

World-space to page-space transformation of the source device context.

### `crBkColorSrc`

Background color (the RGB value) of the source device context. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `iUsageSrc`

Value of the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure. The **iUsageSrc** member can be either the DIB_PAL_COLORS or DIB_RGB_COLORS value.

### `offBmiSrc`

Offset to source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmiSrc`

Size of source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBitsSrc`

Offset to source bitmap bits.

### `cbBitsSrc`

Size of source bitmap bits.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)