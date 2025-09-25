# IWICBitmapSource::GetPixelFormat

## Description

Retrieves the pixel format of the bitmap source..

## Parameters

### `pPixelFormat` [out]

Type: **WICPixelFormatGUID***

Receives the pixel format GUID the bitmap is stored in. For a list of available pixel formats, see the [Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats) topic.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The pixel format returned by this method is not necessarily the pixel format the image is stored as.
The codec may perform a format conversion from the storage pixel format to an output pixel format.