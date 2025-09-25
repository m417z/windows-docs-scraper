# EMRPLGBLT structure

## Description

The **EMRPLGBLT** structure contains members for the [PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt) enhanced metafile record. Note that graphics device interface (GDI) converts the device-dependent bitmap into a device-independent bitmap (DIB) before storing it in the metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `aptlDest`

Array of three points in logical space that identify three corners of the destination parallelogram. The upper-left corner of the source rectangle is mapped to the first point in this array, the upper-right corner to the second point in this array, and the lower-left corner to the third point. The lower-right corner of the source rectangle is mapped to the implicit fourth point in the parallelogram.

### `xSrc`

Logical x-coordinate of the upper-left corner of the source rectangle.

### `ySrc`

Logical y-coordinate of the upper-left corner of the source rectangle.

### `cxSrc`

Logical width of the source.

### `cySrc`

Logical height of the source.

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

### `xMask`

Horizontal pixel offset into mask bitmap.

### `yMask`

Vertical pixel offset into mask bitmap.

### `iUsageMask`

Value of the **bmiColors** member of the mask [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBmiMask`

Offset to mask [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmiMask`

Size of mask [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBitsMask`

Offset to mask bitmap bits.

### `cbBitsMask`

Size of mask bitmap bits.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)