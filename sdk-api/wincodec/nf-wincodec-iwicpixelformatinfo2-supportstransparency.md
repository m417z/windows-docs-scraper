# IWICPixelFormatInfo2::SupportsTransparency

## Description

Returns whether the format supports transparent pixels.

## Parameters

### `pfSupportsTransparency` [out]

Type: **BOOL***

Returns **TRUE** if the pixel format supports transparency; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An indexed pixel format will not return **TRUE** even though it may have some transparency support.

## See also

[IWICPixelFormatInfo2](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpixelformatinfo2)