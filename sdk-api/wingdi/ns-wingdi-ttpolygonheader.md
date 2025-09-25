# TTPOLYGONHEADER structure

## Description

The **TTPOLYGONHEADER** structure specifies the starting position and type of a contour in a TrueType character outline.

## Members

### `cb`

The number of bytes required by the **TTPOLYGONHEADER** structure and [TTPOLYCURVE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolycurve) structure or structures required to describe the contour of the character.

### `dwType`

The type of character outline returned. Currently, this value must be TT_POLYGON_TYPE.

### `pfxStart`

The starting point of the contour in the character outline.

## Remarks

Each **TTPOLYGONHEADER** structure is followed by one or more [TTPOLYCURVE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolycurve) structures.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx)

[TTPOLYCURVE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolycurve)