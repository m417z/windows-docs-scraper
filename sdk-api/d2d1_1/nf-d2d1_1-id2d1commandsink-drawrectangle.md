# ID2D1CommandSink::DrawRectangle

## Description

Draws a rectangle.

## Parameters

### `rect` [in]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The rectangle to be drawn to the command sink.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to stroke the geometry.

### `strokeWidth`

Type: **FLOAT**

The width of the stroke.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of the stroke.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::DrawRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawrectangle(constd2d1_rect_f_id2d1brush_float_id2d1strokestyle))