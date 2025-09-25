# ID2D1DeviceContext4::DrawText(const WCHAR,UINT32,IDWriteTextFormat,const D2D1_RECT_F,ID2D1Brush,ID2D1SvgGlyphStyle,UINT32,D2D1_DRAW_TEXT_OPTIONS,DWRITE_MEASURING_MODE)

## Description

Draws the text within the given layout rectangle.

By default, this method performs baseline snapping and renders color versions of glyphs in color fonts.

## Parameters

### `string` [in]

Type: **const WCHAR***

A pointer to an array of Unicode characters to draw.

### `stringLength`

Type: **UINT32**

The number of characters in string.

### `textFormat` [in]

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/desktop/api/dwrite/nn-dwrite-idwritetextformat)***

An object that describes formatting details of the text to draw, such as the font, the font size, and flow direction.

### `layoutRect` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The size and position of the area in which the text is drawn.

### `defaultFillBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the text.

### `svgGlyphStyle` [in, optional]

Type: **[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)***

Values for context-fill, context-stroke, and context-value that are used when rendering SVG glyphs.

### `colorPaletteIndex`

Type: **UINT32**

The index used to select a color palette within a color font.

### `options`

Type: **[D2D1_DRAW_TEXT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_draw_text_options)**

A value that indicates whether the text should be snapped to pixel boundaries and whether the text should be clipped to the layout rectangle.
The default value is [D2D1_DRAW_TEXT_OPTIONS_NONE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_draw_text_options),
which indicates that text should be snapped to pixel boundaries and it should not be clipped to the layout rectangle.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

A value that indicates how glyph metrics are used to measure text when it is formatted.
The default value is [DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode).

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)