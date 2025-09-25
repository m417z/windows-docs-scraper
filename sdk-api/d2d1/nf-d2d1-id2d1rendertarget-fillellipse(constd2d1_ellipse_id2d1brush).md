## Description

Paints the interior of the specified ellipse.

## Parameters

### `ellipse`

Type: [in] **const [D2D1_ELLIPSE](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_ellipse)***

The position and radius, in device-independent pixels, of the ellipse to paint.

### `brush`

Type: [in] **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the interior of the ellipse.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [FillEllipse](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillellipse(constd2d1_ellipse_id2d1brush))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

For an example, see [How to Draw and Fill a Basic Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-an-ellipse).

## See also

[How to Draw and Fill a Basic Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-an-ellipse)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)