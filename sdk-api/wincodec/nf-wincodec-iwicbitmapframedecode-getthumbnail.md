# IWICBitmapFrameDecode::GetThumbnail

## Description

Retrieves a small preview of the frame, if supported by the codec.

## Parameters

### `ppIThumbnail` [out]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

A pointer that receives a pointer to the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) of the thumbnail.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all formats support thumbnails. Joint Photographic Experts Group (JPEG), Tagged Image File Format (TIFF), and Microsoft Windows Digital Photo (WDP) support thumbnails.

### Note to Implementers

If the codec does not support thumbnails, return WINCODEC_ERROR_CODECNOTHUMBNAIL rather than E_NOTIMPL.