# EMRSETPIXELV structure

## Description

The **EMRSETPIXELV** structure contains members for the [SetPixelV](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelv) enhanced metafile record. When an enhanced metafile is created, calls to [SetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixel) are also recorded in this record.

## Members

### `emr`

The base structure for all record types.

### `ptlPixel`

Logical coordinates of pixel.

### `crColor`

Color value. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixel)

[SetPixelV](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelv)