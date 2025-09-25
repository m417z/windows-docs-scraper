# ID2D1RenderTarget::DrawText(const WCHAR,UINT32,IDWriteTextFormat,const D2D1_RECT_F &,ID2D1Brush,D2D1_DRAW_TEXT_OPTIONS,DWRITE_MEASURING_MODE)

## Description

Draws the specified text using the format information provided by an [IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat) object.

## Parameters

### `string` [in]

Type: **WCHAR***

A pointer to an array of Unicode characters to draw.

### `stringLength`

Type: **UINT**

The number of characters in *string*.

### `textFormat` [in]

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)***

An object that describes formatting details of the text to draw, such as the font, the font size, and flow direction.

### `layoutRect` [ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)**

The size and position of the area in which the text is drawn.

### `defaultFillBrush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the text.

### `options`

Type: **[D2D1_DRAW_TEXT_OPTIONS](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_draw_text_options)**

A value that indicates whether the text should be snapped to pixel boundaries and whether the text should be clipped to the layout rectangle. The default value is [D2D1_DRAW_TEXT_OPTIONS_NONE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_draw_text_options), which indicates that text should be snapped to pixel boundaries and it should not be clipped to the layout rectangle.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

A value that indicates how glyph metrics are used to measure text when it is formatted. The default value is [DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode).

## Remarks

To create an [IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat) object, create an [IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory) and call its [CreateTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createtextformat) method.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [DrawText](https://learn.microsoft.com/windows/win32/Direct2D/id2d1rendertarget-drawtext)) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

For an example, see [How to: Draw Text](https://learn.microsoft.com/windows/win32/Direct2D/how-to--draw-text).

## See also

[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)

[DrawTextLayout](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawtextlayout)

[How to: Draw Text](https://learn.microsoft.com/windows/win32/Direct2D/how-to--draw-text)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[Text Formatting and Layout](https://learn.microsoft.com/windows/win32/DirectWrite/text-formatting-and-layout)