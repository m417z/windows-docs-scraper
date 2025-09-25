# IWICPixelFormatInfo::GetColorContext

## Description

Gets the pixel format's [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext).

## Parameters

### `ppIColorContext` [out]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)****

Pointer that receives the pixel format's color context.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned color context is the default color space for the pixel format. However, if an [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapsource) specifies its own color context, the source's context should be preferred over the pixel format's default.