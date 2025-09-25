# ID2D1DeviceContext4::DrawSvgGlyphRun

## Description

Draws a color glyph run that has the format of DWRITE_GLYPH_IMAGE_FORMATS_SVG.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The origin of the baseline for the glyph run.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The glyphs to render.

### `defaultFillBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the specified glyphs.

### `svgGlyphStyle` [in, optional]

Type: **[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)***

Values for context-fill, context-stroke, and context-value that are used when rendering SVG glyphs.

### `colorPaletteIndex`

Type: **UINT32**

The index used to select a color palette within a color font. Note that this not the same as the paletteIndex in the
DWRITE_COLOR_GLYPH_RUN struct, which is not relevant for SVG glyphs.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Indicates the measuring method used for text layout.

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)