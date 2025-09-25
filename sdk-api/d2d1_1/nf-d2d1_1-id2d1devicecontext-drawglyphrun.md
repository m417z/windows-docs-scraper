# ID2D1DeviceContext::DrawGlyphRun

## Description

Draws a series of glyphs to the device context.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

Origin of first glyph in the series.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The glyphs to render.

### `glyphRunDescription` [in, optional]

Type: **const [DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run_description)***

Supplementary glyph series information.

### `foregroundBrush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush that defines the text color.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring mode of the glyph series, used to determine the advances and offsets. The default value is DWRITE_MEASURING_MODE_NATURAL.

## Remarks

The *glyphRunDescription* is ignored when rendering, but can be useful for printing and serialization of rendering commands, such as to an XPS or SVG file. This extends [ID2D1RenderTarget::DrawGlyphRun](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawglyphrun), which lacked the glyph run description.

## See also

[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1RenderTarget::DrawGlyphRun](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawglyphrun)