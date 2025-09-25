# IDWriteTextLayout::SetDrawingEffect

## Description

 Sets the application-defined drawing effect.

## Parameters

### `drawingEffect`

Type: **IUnknown***

Application-defined drawing effects that apply to the range. This data object will be passed back to the application's drawing callbacks for final rendering.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

The text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An [ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush), such as a color or gradient brush, can be set as a drawing effect if you are using the [ID2D1RenderTarget::DrawTextLayout](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawtextlayout) to draw text and that brush will be used to draw the specified range of text.

 This drawing effect is associated with the specified range and will be passed back
to the application by way of the callback when the range is drawn at drawing time.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)