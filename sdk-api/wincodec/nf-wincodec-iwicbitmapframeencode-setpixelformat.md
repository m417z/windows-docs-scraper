# IWICBitmapFrameEncode::SetPixelFormat

## Description

Requests that the encoder use the specified pixel format.

## Parameters

### `pPixelFormat` [in, out]

Type: **WICPixelFormatGUID***

On input, the requested pixel format GUID. On output, the closest pixel format GUID supported by the encoder; this may be different than the requested format. For a list of pixel format GUIDs, see [Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats).

## Return value

Type: **HRESULT**

Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **WINCODEC_ERR_WRONGSTATE** | The [IWICBitmapFrameEncode::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-initialize) method was not called. |

## Remarks

The encoder might not support the requested pixel format. If not, **SetPixelFormat** returns the closest match in the memory block that *pPixelFormat* points to. If the returned pixel format doesn't match the requested format, you must use an [IWICFormatConverter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicformatconverter) object to convert the pixel data.

## See also

[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)

[Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats)