# IWICBitmapDecoder::GetThumbnail

## Description

Retrieves a bitmap thumbnail of the image, if one exists

## Parameters

### `ppIThumbnail` [out]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

Receives a pointer to the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) of the thumbnail.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned thumbnail can be of any size, so the caller should scale the thumbnail to the desired size. The only Windows provided image formats that support thumbnails are JPEG, TIFF, and JPEG-XR. If the thumbnail is not available, this will return [WINCODEC_ERR_CODECNOTHUMBNAIL](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-error-codes).