# IWICBitmapEncoder::SetPalette

## Description

Sets the global palette for the image.

## Parameters

### `pIPalette` [in]

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

The [IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette) to use as the global palette.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

Returns WINCODEC_ERR_UNSUPPORTEDOPERATION if the feature is not supported by the encoder.

## Remarks

Only GIF images support an optional global palette, and you must set the global palette before adding any frames to the image. You only need to set the palette for indexed pixel formats.