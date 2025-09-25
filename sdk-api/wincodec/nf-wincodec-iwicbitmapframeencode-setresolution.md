# IWICBitmapFrameEncode::SetResolution

## Description

Sets the physical resolution of the output image.

## Parameters

### `dpiX` [in]

Type: **double**

The horizontal resolution value.

### `dpiY` [in]

Type: **double**

The vertical resolution value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Windows Imaging Component (WIC) doesn't perform any special processing as a result of DPI resolution values. For example, data returned from [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) isn't scaled by the DPI. The app must handle DPI resolution.