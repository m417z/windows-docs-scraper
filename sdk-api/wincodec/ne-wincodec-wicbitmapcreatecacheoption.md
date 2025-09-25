# WICBitmapCreateCacheOption enumeration

## Description

Specifies the desired cache usage.

## Constants

### `WICBitmapNoCache:0`

Do not cache the bitmap.

### `WICBitmapCacheOnDemand:0x1`

Cache the bitmap when needed.

### `WICBitmapCacheOnLoad:0x2`

Cache the bitmap at initialization.

### `WICBITMAPCREATECACHEOPTION_FORCE_DWORD:0x7fffffff`

## Remarks

The **CreateBitmap** of the [IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory) interface does not support WICBitmapNoCache when the *pixelFormat* is a native pixel format provided by Windows Imaging Component (WIC).