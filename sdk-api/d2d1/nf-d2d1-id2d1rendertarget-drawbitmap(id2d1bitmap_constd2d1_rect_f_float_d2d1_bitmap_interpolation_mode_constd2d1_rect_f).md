# ID2D1RenderTarget::DrawBitmap

## Description

Draws the specified bitmap after scaling it to the size of the specified rectangle.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap to render.

### `destinationRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

The size and position, in device-independent pixels in the render target's coordinate space, of the area to which the bitmap is drawn; **NULL** to draw the selected portion of the bitmap at the origin of the render target. If the rectangle is specified but not well-ordered, nothing is drawn, but the render target does not enter an error state.

### `opacity`

Type: **FLOAT**

A value between 0.0f and 1.0f, inclusive, that specifies an opacity value to apply to the bitmap; this value is multiplied against the alpha values of the bitmap's contents. The default value is 1.0f.

### `interpolationMode`

Type: **[D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode)**

The interpolation mode to use if the bitmap is scaled or rotated by the drawing operation. The default value is [D2D1_BITMAP_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode).

### `sourceRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

The size and position, in device-independent pixels in the bitmap's coordinate space, of the area within the bitmap to be drawn; **NULL** to draw the entire bitmap.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [DrawBitmap](https://learn.microsoft.com/windows/win32/Direct2D/id2d1rendertarget-drawbitmap)) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

For an example, see [How to Draw a Bitmap](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-a-bitmap). For an example showing how to load a bitmap from a resource or a file, see [How to Load a Bitmap from a Resource](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-bitmap-from-a-resource) and [How to Load a Bitmap from a File](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-direct2d-bitmap-from-a-file).

## See also

[How to Draw a Bitmap](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-a-bitmap)

[How to Load a Bitmap from a File](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-direct2d-bitmap-from-a-file)

[How to Load a Bitmap from a Resource](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-bitmap-from-a-resource)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)