# EMRTRANSPARENTBLT structure

## Description

The **EMRTRANSPARENTBLT** structure contains members for the [TransparentBLT](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-transparentblt) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Inclusive bounds, in device units.

### `xDest`

Logical x coordinate of the upper-left corner of the destination rectangle.

### `yDest`

Logical y coordinate of the upper-left corner of the destination rectangle.

### `cxDest`

Logical width of the destination rectangle.

### `cyDest`

Logical height of the destination rectangle.

### `dwRop`

Stores the transparent color.

### `xSrc`

Logical x coordinate of the upper-left corner of the source rectangle.

### `ySrc`

Logical y coordinate of the upper-left corner of the source rectangle.

### `xformSrc`

World-space to page-space transformation of the source device context.

### `crBkColorSrc`

Background color (the RGB value) of the source device context. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `iUsageSrc`

Source bitmap information color table usage (DIB_RGB_COLORS).

### `offBmiSrc`

Offset to the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmiSrc`

Size of the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBitsSrc`

Offset to the source bitmap bits.

### `cbBitsSrc`

Size of the source bitmap bits.

### `cxSrc`

Width of the source rectangle, in logical units.

### `cySrc`

Height of the source rectangle, in logical units.

## Remarks

This structure is to be used during metafile playback.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[TransparentBLT](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-transparentblt)