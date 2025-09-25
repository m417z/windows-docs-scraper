# GLYPHMETRICS structure

## Description

The **GLYPHMETRICS** structure contains information about the placement and orientation of a glyph in a character cell.

## Members

### `gmBlackBoxX`

The width of the smallest rectangle that completely encloses the glyph (its black box).

### `gmBlackBoxY`

The height of the smallest rectangle that completely encloses the glyph (its black box).

### `gmptGlyphOrigin`

The x- and y-coordinates of the upper left corner of the smallest rectangle that completely encloses the glyph.

### `gmCellIncX`

The horizontal distance from the origin of the current character cell to the origin of the next character cell.

### `gmCellIncY`

The vertical distance from the origin of the current character cell to the origin of the next character cell.

## Remarks

Values in the **GLYPHMETRICS** structure are specified in device units.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea)