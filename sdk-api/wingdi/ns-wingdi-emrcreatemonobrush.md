# EMRCREATEMONOBRUSH structure

## Description

The **EMRCREATEMONOBRUSH** structure contains members for the [CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush) (when passed a monochrome bitmap) or [CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush) (when passed a monochrome DIB) enhanced metafile records.

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

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)