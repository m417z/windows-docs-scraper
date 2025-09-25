# IWICBitmapSource::GetResolution

## Description

Retrieves the sampling rate between pixels and physical world measurements.

## Parameters

### `pDpiX` [out]

Type: **double***

A pointer that receives the x-axis dpi resolution.

### `pDpiY` [out]

Type: **double***

A pointer that receives the y-axis dpi resolution.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some formats, such as GIF and ICO, do not have full DPI support.
For GIF, this method calculates the DPI values from the aspect ratio, using a base DPI of (96.0, 96.0).
The ICO format does not support DPI at all, and the method always returns (96.0,96.0) for ICO images.

Additionally, WIC itself does not transform images based on the DPI values in an image.
It is up to the caller to transform an image based on the resolution returned.