# MAT2 structure

## Description

The **MAT2** structure contains the values for a transformation matrix used by the [GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea) function.

## Members

### `eM11`

A fixed-point value for the M11 component of a 3 by 3 transformation matrix.

### `eM12`

A fixed-point value for the M12 component of a 3 by 3 transformation matrix.

### `eM21`

A fixed-point value for the M21 component of a 3 by 3 transformation matrix.

### `eM22`

A fixed-point value for the M22 component of a 3 by 3 transformation matrix.

## Remarks

The identity matrix produces a transformation in which the transformed graphical object is identical to the source object. In the identity matrix, the value of **eM11** is 1, the value of **eM12** is zero, the value of **eM21** is zero, and the value of **eM22** is 1.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea)