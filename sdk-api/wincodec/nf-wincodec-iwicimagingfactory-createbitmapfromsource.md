# IWICImagingFactory::CreateBitmapFromSource

## Description

Creates a [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) from a [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource).

## Parameters

### `pIBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) to create the bitmap from.

### `option` [in]

Type: **[WICBitmapCreateCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapcreatecacheoption)**

The cache options of the new bitmap. This can be one of the values in the [WICBitmapCreateCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapcreatecacheoption) enumeration.

| Value | Meaning |
| --- | --- |
| **WICBitmapNoCache** | Do not create a system memory copy. Share the bitmap with the source. |
| **WICBitmapCacheOnDemand** | Create a system memory copy when the bitmap is first used. |
| **WICBitmapCacheOnLoad** | Create a system memory copy when this method is called. |

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.