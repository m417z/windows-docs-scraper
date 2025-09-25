# IWICBitmapEncoder::SetPreview

## Description

Sets the global preview for the image.

## Parameters

### `pIPreview` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) to use as the global preview.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

Returns WINCODEC_ERR_UNSUPPORTEDOPERATION if the feature is not supported by the encoder.