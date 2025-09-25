# ID2D1Bitmap1::Map

## Description

Maps the given bitmap into memory.

## Parameters

### `options`

Type: **[D2D1_MAP_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_map_options)**

The options used in mapping the bitmap into memory.

### `mappedRect` [out]

Type: **[D2D1_MAPPED_RECT](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_mapped_rect)***

When this method returns, contains a reference to the rectangle that is mapped into memory.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | One or more arguments are not valid |
| D3DERR_DEVICELOST | The device has been lost but cannot be reset at this time. |

## Remarks

**Note** You can't use bitmaps for some purposes while mapped. Particularly, the [ID2D1Bitmap::CopyFromBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-copyfrombitmap) method doesn't work if either the source or destination bitmap is mapped.

The bitmap must have been created with the **D2D1_BITMAP_OPTIONS_CPU_READ** flag specified.

## See also

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::CreateBitmapFromDxgiSurface](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmapfromdxgisurface(idxgisurface_constd2d1_bitmap_properties1__id2d1bitmap1))

[ID2D1RenderTarget::CreateSharedBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-createsharedbitmap)