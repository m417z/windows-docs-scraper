# EMRCREATEDIBPATTERNBRUSHPT structure

## Description

The **EMRCREATEDIBPATTERNBRUSHPT** structure contains members for the [CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt) enhanced metafile record. The [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure is followed by the bitmap bits that form a packed device-independent bitmap (DIB).

## Members

### `emr`

The base structure for all record types.

### `ihBrush`

Index of brush in handle table.

### `iUsage`

Value specifying whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure was provided and, if so, whether **bmiColors** contains explicit red, green, blue (RGB) values or indices. The **iUsage** member must be either the DIB_PAL_COLORS or DIB_RGB_COLORS value.

### `offBmi`

Offset to [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmi`

Size of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBits`

Offset to bitmap bits.

### `cbBits`

Size of bitmap bits.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)