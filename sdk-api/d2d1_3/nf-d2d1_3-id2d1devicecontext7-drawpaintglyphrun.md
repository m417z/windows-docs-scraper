## Description

To support COLR v1, draws a color glyph run that has the format of [DWRITE_GLYPH_IMAGE_FORMATS_COLR_PAINT_TREE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_glyph_image_formats).

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/direct2d/d2d1-point-2f)**

The baseline.

### `glyphRun`

Type: \_In\_ **CONST [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run) \***

The glyph run to draw.

### `defaultFillBrush`

Type: \_In\_opt\_ **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush) \***

Default fill brush.

### `colorPaletteIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The index used to select a color palette within a color font. Note that this not the same as the *paletteIndex* in the [DWRITE_COLOR_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite_2/ns-dwrite_2-dwrite_color_glyph_run) struct, which is not relevant for paint glyphs.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode) = DWRITE_MEASURING_MODE_NATURAL**

Specifies measuring mode for positioning glyphs in the run.

## Remarks

## See also