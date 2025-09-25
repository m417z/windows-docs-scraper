# IWICBitmapEncoder::SetThumbnail

## Description

Sets the global thumbnail for the image.

## Parameters

### `pIThumbnail` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) to set as the global thumbnail.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

Returns WINCODEC_ERR_UNSUPPORTEDOPERATION if the feature is not supported by the encoder.