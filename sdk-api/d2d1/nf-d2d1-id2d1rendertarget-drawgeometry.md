# ID2D1RenderTarget::DrawGeometry

## Description

Draws the outline of the specified geometry using the specified stroke style.

## Parameters

### `geometry` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry to draw.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the geometry's stroke.

### `strokeWidth`

Type: **FLOAT**

The width of the stroke, in device-independent pixels. The value must be greater than or equal to 0.0f. If this parameter isn't specified, it defaults to 1.0f. The stroke is centered on the line.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of stroke to apply to the geometry's outline, or **NULL** to paint a solid stroke.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as **DrawGeometry**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

For an example, see [How to Draw and Fill a Complex Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-and-fill-a-complex-shape).

## See also

[Geometries](https://learn.microsoft.com/windows/win32/Direct2D/geometries)

[Geometries Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-geometries-overview)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)