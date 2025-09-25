# IWICImagingFactory::CreateBitmap

## Description

Creates an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) object.

## Parameters

### `uiWidth` [in]

Type: **UINT**

The width of the new bitmap .

### `uiHeight` [in]

Type: **UINT**

The height of the new bitmap.

### `pixelFormat` [in]

Type: **REFWICPixelFormatGUID**

The pixel format of the new bitmap.

### `option` [in]

Type: **[WICBitmapCreateCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapcreatecacheoption)**

The cache creation options of the new bitmap. This can be one of the values in the [WICBitmapCreateCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapcreatecacheoption) enumeration.

| Value | Meaning |
| --- | --- |
| **WICBitmapCacheOnDemand** | Allocates system memory for the bitmap at initialization. |
| **WICBitmapCacheOnLoad** | Allocates system memory for the bitmap when the bitmap is first used. |
| **WICBitmapNoCache** | This option is not valid for this method and should not be used. |

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats)