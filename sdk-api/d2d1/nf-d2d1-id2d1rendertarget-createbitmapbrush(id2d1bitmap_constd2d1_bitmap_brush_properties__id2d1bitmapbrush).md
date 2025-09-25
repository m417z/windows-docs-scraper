# ID2D1RenderTarget::CreateBitmapBrush(ID2D1Bitmap,const D2D1_BITMAP_BRUSH_PROPERTIES &,ID2D1BitmapBrush)

## Description

Creates an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) from the specified bitmap. The brush uses the default values for its opacity and transform.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap contents of the new brush.

### `bitmapBrushProperties` [ref]

Type: **const [D2D1_BITMAP_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_bitmap_brush_properties)**

The extend modes and interpolation mode of the new brush.

### `bitmapBrush` [out]

Type: **[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)****

When this method returns, contains a pointer to a pointer to the new brush. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The bitmap brush created by this method has an opacity of 1.0f and the identity matrix as its transform.

## Examples

For an example showing how to paint an area with a bitmap brush, see [How to Create a Bitmap Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-bitmap-brush).

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[How to Create a Bitmap Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-bitmap-brush)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)