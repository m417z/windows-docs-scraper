# ID2D1DeviceContext::CreateBitmapBrush

## Description

Creates a bitmap brush, the input image is a Direct2D bitmap object.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap to use as the brush.

### `bitmapBrushProperties` [in, optional]

Type: **[D2D1_BITMAP_BRUSH_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_brush_properties1)***

A bitmap brush properties structure.

### `brushProperties` [in, optional]

Type: **[D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_brush_properties)***

A brush properties structure.

### `bitmapBrush` [out]

Type: **[ID2D1BitmapBrush1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmapbrush1)****

The address of the newly created bitmap brush object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[D2D1_BITMAP_BRUSH_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_brush_properties1)

[D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties_id2d1bitmap))

[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)

[ID2D1BitmapBrush1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmapbrush1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)