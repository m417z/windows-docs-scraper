# ID2D1SvgGlyphStyle::SetFill

## Description

Provides values to an SVG glyph for fill.

## Parameters

### `brush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

Describes how the area is painted. A null brush will cause the context-fill value to come from
the [defaultFillBrush](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1devicecontext4-drawtext(constwchar_uint32_idwritetextformat_constd2d1_rect_f__id2d1brush_id2d1svgglyphstyle_uint32_d2d1_draw_text_options_dwrite_measuring_mode)). If the defaultFillBrush is also null, the context-fill value will be 'none'.
To set the ‘context-fill’ value, this method uses the provided brush with its opacity set to 1. To set the ‘context-fill-opacity’ value, this method uses the opacity of the provided brush.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)