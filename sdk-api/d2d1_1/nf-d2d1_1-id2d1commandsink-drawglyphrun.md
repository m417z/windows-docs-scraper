# ID2D1CommandSink::DrawGlyphRun

## Description

Indicates the glyphs to be drawn.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The upper left corner of the baseline.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The glyphs to render.

### `glyphRunDescription` [in, optional]

Type: **const [DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run_description)***

Additional non-rendering information about the glyphs.

### `foregroundBrush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to fill the glyphs.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring mode to apply to the glyphs.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

[DrawText](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-drawtext) and [DrawTextLayout](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawtextlayout) are broken down into glyph runs and rectangles by the time the command sink is processed. So, these methods aren't available on the command sink. Since the application may require additional callback processing when calling **DrawTextLayout**, this semantic can't be easily preserved in the command list.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1DeviceContext::DrawGlyphRun](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawglyphrun)