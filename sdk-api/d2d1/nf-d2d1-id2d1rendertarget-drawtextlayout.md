# ID2D1RenderTarget::DrawTextLayout

## Description

Draws the formatted text described by the specified [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) object.

## Parameters

### `origin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point, described in device-independent pixels, at which the upper-left corner of the text described by *textLayout* is drawn.

### `textLayout` [in]

Type: **[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)***

The formatted text to draw. Any drawing effects that do not inherit from [ID2D1Resource](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1resource) are ignored. If there are drawing effects that inherit from **ID2D1Resource** that are not brushes, this method fails and the render target is put in an error state.

### `defaultFillBrush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint any text in *textLayout* that does not already have a brush associated with it as a drawing effect (specified by the [IDWriteTextLayout::SetDrawingEffect](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-setdrawingeffect) method).

### `options`

Type: **[D2D1_DRAW_TEXT_OPTIONS](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_draw_text_options)**

A value that indicates whether the text should be snapped to pixel boundaries and whether the text should be clipped to the layout rectangle. The default value is [D2D1_DRAW_TEXT_OPTIONS_NONE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_draw_text_options), which indicates that text should be snapped to pixel boundaries and it should not be clipped to the layout rectangle.

## Remarks

When drawing the same text repeatedly, using the **DrawTextLayout** method is more efficient than using the [DrawText](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawtext(constwchar_uint32_idwritetextformat_constd2d1_rect_f__id2d1brush_d2d1_draw_text_options_dwrite_measuring_mode)) method because the text doesn't need to be formatted and the layout processed with each call.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as **DrawTextLayout**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[Text Formatting and Layout](https://learn.microsoft.com/windows/win32/DirectWrite/text-formatting-and-layout)