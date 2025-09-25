# EMRSTRETCHDIBITS structure

## Description

The **EMRSTRETCHDIBITS** structure contains members for the [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `xDest`

Logical x-coordinate of the upper-left corner of the destination rectangle.

### `yDest`

Logical y-coordinate of the upper-left corner of the destination rectangle.

### `xSrc`

Logical x-coordinate of the upper-left corner of the source rectangle.

### `ySrc`

Logical y-coordinate of the upper-left corner of the source rectangle.

### `cxSrc`

Width of the source rectangle, in logical units.

### `cySrc`

Height of the source rectangle, in logical units.

### `offBmiSrc`

Offset to the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmiSrc`

Size of the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBitsSrc`

Offset to source bitmap bits.

### `cbBitsSrc`

Size of source bitmap bits.

### `iUsageSrc`

Value of the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure. The **iUsageSrc** member can be either the DIB_PAL_COLORS or DIB_RGB_COLORS value.

### `dwRop`

Raster-operation code. These codes define how the color data of the source rectangle is to be combined with the color data of the destination rectangle to achieve the final color.

### `cxDest`

Logical width of the destination rectangle.

### `cyDest`

Logical height of the destination rectangle.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)