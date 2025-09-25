# ID2D1RenderTarget::CreateBitmapBrush

## Description

Creates an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) from the specified bitmap.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap contents of the new brush.

### `bitmapBrushProperties` [in, optional]

Type: **[D2D1_BITMAP_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_bitmap_brush_properties)***

The extend modes and interpolation mode of the new brush, or **NULL**. If you set this parameter to **NULL**, the brush defaults to the [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode) horizontal and vertical extend modes and the [D2D1_BITMAP_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode) interpolation mode.

### `brushProperties` [in, optional]

Type: **[D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_brush_properties)***

A structure that contains the opacity and transform of the new brush, or **NULL**. If you set this parameter to **NULL**, the brush sets the opacity member to 1.0F and the transform member to the identity matrix.

### `bitmapBrush` [out]

Type: **[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)****

When this method returns, this output parameter contains a pointer to a pointer to the new brush. Pass this parameter uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[How to Create a Bitmap Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-bitmap-brush)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)