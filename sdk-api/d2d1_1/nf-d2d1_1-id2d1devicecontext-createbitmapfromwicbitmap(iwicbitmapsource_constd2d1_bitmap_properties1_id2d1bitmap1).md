# ID2D1DeviceContext::CreateBitmapFromWicBitmap

## Description

Creates a Direct2D bitmap by copying a WIC bitmap.

## Parameters

### `wicBitmapSource` [in]

Type: **IWICBitmapSource***

The WIC bitmap source to copy from.

### `bitmapProperties` [in, optional]

Type: **const [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))***

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

## Remarks

Starting with Windows 8.1, the *bitmapProperties* parameter is optional. When it is not specified, the created bitmap inherits the pixel format and alpha mode from *wicBitmapSource*. For a list of supported pixel formats and alpha modes, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

When the *bitmapProperties* parameter is specified, the value in *bitmapProperties->pixelFormat* must either be [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) or must match the WIC pixel format in *wicBitmapSource*.

When *bitmapProperties->pixelFormat.alphaMode* is set to [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode), the newly created bitmap inherits the alpha mode from *wicBitmapSource*. When *bitmapProperties->pixelFormat.alphaMode* is set to **D2D1_ALPHA_MODE_PREMULTIPLIED**, **D2D1_ALPHA_MODE_STRAIGHT**, or **D2D1_ALPHA_MODE_IGNORE**, this forces the newly created bitmap to use the specified alpha mode.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)