# IWICPlanarFormatConverter::CanConvert

## Description

Query if the format converter can convert from one format to another.

## Parameters

### `pSrcPixelFormats` [in]

An array of WIC pixel formats that represents source image planes.

### `cSrcPlanes`

The number of source pixel formats specified by the *pSrcFormats* parameter.

### `dstPixelFormat` [in]

The destination interleaved pixel format.

### `pfCanConvert` [out]

True if the conversion is supported.

## Return value

If the conversion is not supported, this method returns S_OK, but **pfCanConvert* is set to FALSE.

If this method fails, the out parameter *pfCanConvert* is invalid.

## Remarks

To specify an interleaved input pixel format, provide a length 1 array to *pSrcPixelFormats*.

## See also

[IWICPlanarFormatConverter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarformatconverter)