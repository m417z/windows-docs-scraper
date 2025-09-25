## Description

Draws the outline of the specified ellipse using the specified stroke style.

## Parameters

### `ellipse`

Type: [in] **const [D2D1_ELLIPSE](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_ellipse) &**

The position and radius of the ellipse to draw, in device-independent pixels.

### `brush`

Type: [in] **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the ellipse's outline.

### `strokeWidth`

Type: [in] **FLOAT**

The width of the stroke, in device-independent pixels. The value must be greater than or equal to 0.0f. If this parameter isn't specified, it defaults to 1.0f. The stroke is centered on the line.

### `strokeStyle`

Type: [in, optional] **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of stroke to apply to the ellipse's outline, or **NULL** to paint a solid stroke.

## Remarks

The [DrawEllipse](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawellipse(constd2d1_ellipse_id2d1brush_float_id2d1strokestyle)) method doesn't return an error code if it fails. To determine whether a drawing operation (such as **DrawEllipse**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

For an example, see [How to Draw and Fill a Basic Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-an-ellipse).

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)