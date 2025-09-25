# DWRITE_COLOR_GLYPH_RUN structure

## Description

Contains the information needed by renderers to draw glyph runs with glyph color information.
All coordinates are in device independent pixels (DIPs).

## Members

### `glyphRun`

Glyph run to draw for this layer.

### `glyphRunDescription`

Pointer to the glyph run description for this layer. This may be **NULL**. For example, when the original glyph run is split into multiple layers, one layer might have a description and the others have none.

### `baselineOriginX`

X coordinate of the baseline origin for the layer.

### `baselineOriginY`

Y coordinate of the baseline origin for the layer.

### `runColor`

Color value of the run; if all members are zero, the run should be drawn using the current brush.

### `paletteIndex`

Zero-based index into the font’s color palette; if this is **0xFFFF**, the run should be drawn using the current brush.