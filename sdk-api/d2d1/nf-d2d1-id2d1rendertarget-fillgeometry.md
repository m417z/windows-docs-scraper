# ID2D1RenderTarget::FillGeometry

## Description

Paints the interior of the specified geometry.

## Parameters

### `geometry` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry to paint.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the geometry's interior.

### `opacityBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The opacity mask to apply to the geometry, or **NULL** for no opacity mask. If an opacity mask (the *opacityBrush* parameter) is specified, *brush* must be an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) that has its x- and y-extend modes set to [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode). For more information, see the Remarks section.

## Remarks

If the *opacityBrush* parameter is not **NULL**, the alpha value of each pixel of the mapped *opacityBrush* is used to determine the resulting opacity of each corresponding pixel of the geometry. Only the alpha value of each color in the brush is used for this processing; all other color information is ignored.

The alpha value specified by the brush is multiplied by the alpha value of the geometry after the geometry has been painted by *brush*.

When this method fails, it does not return an error code. To determine whether a drawing operation (such as **FillGeometry**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) method.

## Examples

For an example, see [How to Draw and Fill a Complex Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-and-fill-a-complex-shape).

## See also

[D2D1_FILL_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode)

[Geometries](https://learn.microsoft.com/windows/win32/Direct2D/geometries)

[Geometries Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-geometries-overview)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)