# IWICFormatConverter::CanConvert

## Description

Determines if the source pixel format can be converted to the destination pixel format.

## Parameters

### `srcPixelFormat` [in]

Type: **REFWICPixelFormatGUID**

The source pixel format.

### `dstPixelFormat` [in]

Type: **REFWICPixelFormatGUID**

The destination pixel format.

### `pfCanConvert` [out]

Type: **BOOL***

A pointer that receives a value indicating whether the source pixel format can be converted to the destination pixel format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWICFormatConverter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicformatconverter)

[Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats)