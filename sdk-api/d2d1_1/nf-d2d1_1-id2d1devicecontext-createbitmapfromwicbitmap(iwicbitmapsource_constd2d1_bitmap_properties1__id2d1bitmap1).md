# ID2D1DeviceContext::CreateBitmapFromWicBitmap(IWICBitmapSource,const D2D1_BITMAP_PROPERTIES1 &,ID2D1Bitmap1)

## Description

Creates a Direct2D bitmap by copying a WIC bitmap.

## Parameters

### `wicBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmapfromwicbitmap(iwicbitmapsource_constd2d1_bitmap_properties1__id2d1bitmap1))***

The WIC bitmap source to copy from.

### `bitmapProperties` [in, ref, optional]

Type: **const [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))**

A bitmap properties structure that specifies bitmap creation options.

### `bitmap` [out]

Type: **[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)****

The address of the newly created bitmap object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)