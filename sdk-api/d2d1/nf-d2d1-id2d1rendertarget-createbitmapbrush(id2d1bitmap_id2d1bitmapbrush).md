# ID2D1RenderTarget::CreateBitmapBrush(ID2D1Bitmap,ID2D1BitmapBrush)

## Description

Creates an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) from the specified bitmap. The brush uses the default values for its extend mode, interpolation mode, opacity, and transform.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap contents of the new brush.

### `bitmapBrush` [out]

Type: **[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)****

When this method returns, contains a pointer to a pointer to the new brush. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The bitmap brush created by this method has [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode) horizontal and vertical extend modes and the [D2D1_BITMAP_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode) interpolation mode. Its opacity is 1.0f, and its transform is the identity matrix.

## Examples

For an example showing how to paint an area with a bitmap brush, see [How to Create a Bitmap Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-bitmap-brush).

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[How to Create a Bitmap Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-bitmap-brush)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)