# DWRITE_GLYPH_RUN structure

## Description

Contains the information needed by renderers to draw glyph runs.
All coordinates are in device independent pixels (DIPs).

## Members

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

The physical font face object to draw with.

### `fontEmSize`

Type: **FLOAT**

The logical size of the font in DIPs (equals 1/96 inch), not points.

### `glyphCount`

Type: **UINT32**

The number of glyphs in the glyph run.

### `glyphIndices`

Type: **const UINT16***

A pointer to an array of indices to render for the glyph run.

### `glyphAdvances`

Type: **const FLOAT***

A pointer to an array containing glyph advance widths for the glyph run.

### `glyphOffsets`

Type: **const [DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

A pointer to an array containing glyph offsets for the glyph run.

### `isSideways`

Type: **BOOL**

If true, specifies that glyphs are rotated 90 degrees to the left and vertical metrics are used. Vertical writing is achieved by specifying **isSideways** = true and rotating the entire run 90 degrees to the right via a rotate transform.

### `bidiLevel`

Type: **UINT32**

The implicit resolved bidi level of the run. Odd levels indicate right-to-left languages like Hebrew and Arabic, while even levels indicate left-to-right languages like English and Japanese (when written horizontally). For right-to-left languages, the text origin is on the right, and text should be drawn to the left.