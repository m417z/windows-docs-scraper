# IWICImagingFactory::CreateBitmapFromSourceRect

## Description

Creates an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) from a specified rectangle of an [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource).

## Parameters

### `pIBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) to create the bitmap from.

### `x` [in]

Type: **UINT**

The horizontal coordinate of the upper-left corner of the rectangle.

### `y` [in]

Type: **UINT**

The vertical coordinate of the upper-left corner of the rectangle.

### `width` [in]

Type: **UINT**

The width of the rectangle and the new bitmap.

### `height` [in]

Type: **UINT**

The height of the rectangle and the new bitmap.

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Providing a rectangle that is larger than the source will produce undefined results.

This method always creates a separate copy of the source image, similar to the cache option [WICBitmapCacheOnLoad](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapcreatecacheoption).