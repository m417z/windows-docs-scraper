# ID2D1DeviceContext4::DrawTextLayout

## Description

Draws a text layout object. If the layout is not subsequently changed, this can be more efficient than DrawText when drawing the same layout repeatedly.

## Parameters

### `origin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The point, described in device-independent pixels, at which the upper-left corner of the text described by *textLayout* is drawn.

### `textLayout` [in]

Type: **[IDWriteTextLayout](https://learn.microsoft.com/windows/desktop/api/dwrite/nn-dwrite-idwritetextlayout)***

The formatted text to draw. Any drawing effects that do not inherit from [ID2D1Resource](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1resource) are ignored. If there are drawing effects that inherit from **ID2D1Resource** that are not brushes, this method fails and the render target is put in an error state.

### `defaultFillBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the text.

### `svgGlyphStyle` [in, optional]

Type: **[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)***

The values for context-fill, context-stroke, and context-value that are used when rendering SVG glyphs.

### `colorPaletteIndex`

Type: **UINT32**

The index used to select a color palette within a color font.

### `options`

Type: **[D2D1_DRAW_TEXT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_draw_text_options)**

A value that indicates whether the text should be snapped to pixel boundaries and whether the text should be clipped to the layout rectangle.
The default value is [D2D1_DRAW_TEXT_OPTIONS_NONE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_draw_text_options),
which indicates that text should be snapped to pixel boundaries and it should not be clipped to the layout rectangle.

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)