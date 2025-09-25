# GLYPHMETRICSFLOAT structure

## Description

The **GLYPHMETRICSFLOAT** structure contains information about the placement and orientation of a glyph in a character cell.

## Members

### `gmfBlackBoxX`

Specifies the width of the smallest rectangle (the glyph's black box) that completely encloses the glyph.

### `gmfBlackBoxY`

Specifies the height of the smallest rectangle (the glyph's black box) that completely encloses the glyph.

### `gmfptGlyphOrigin`

Specifies the x and y coordinates of the upper-left corner of the smallest rectangle that completely encloses the glyph.

### `gmfCellIncX`

Specifies the horizontal distance from the origin of the current character cell to the origin of the next character cell.

### `gmfCellIncY`

Specifies the vertical distance from the origin of the current character cell to the origin of the next character cell.

## Remarks

The values of **GLYPHMETRICSFLOAT** are specified as notional units.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[POINTFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfloat)

[Structures](https://learn.microsoft.com/windows/desktop/OpenGL/structures)

[wglUseFontOutlines](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglusefontoutlinesa)