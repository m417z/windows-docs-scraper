# IWICBitmapDecoder::GetPreview

## Description

Retrieves a preview image, if supported.

## Parameters

### `ppIBitmapSource` [out]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

Receives a pointer to the preview bitmap if supported.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all formats support previews. Only the native Microsoft Windows Digital Photo (WDP) codec support previews.