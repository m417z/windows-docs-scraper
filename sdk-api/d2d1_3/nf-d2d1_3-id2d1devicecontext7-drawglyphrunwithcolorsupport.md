## Description

Draws a glyph run, using color representations of glyphs if available in the font. We recommended that you render color glyphs by using this method.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/direct2d/d2d1-point-2f)**

The baseline.

### `glyphRun`

Type: \_In\_ **CONST [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run) \***

The glyph run to draw.

### `glyphRunDescription`

Type: \_In\_opt\_ **CONST [DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run) \***

A description of the glyph run to draw.

### `foregroundBrush`

Type: \_In\_opt\_ **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush) \***

Foreground brush for the text.

### `svgGlyphStyle`

Type: \_In\_opt\_ **[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/win32/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle) \***

The glyph style.

### `colorPaletteIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font-defined color palette to use.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode) = DWRITE_MEASURING_MODE_NATURAL**

Specifies measuring mode for positioning glyphs in the run.

### `bitmapSnapOption`

Type: **[D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION](https://learn.microsoft.com/windows/win32/api/d2d1_3/ne-d2d1_3-d2d1_color_bitmap_glyph_snap_option) = D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_DEFAULT**

Snap options.

## Remarks

## See also