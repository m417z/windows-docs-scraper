# WICSetEncoderFormat\_Proxy function

Proxy function for negotiating the pixel format and the palette for the encoder.

## Parameters

*pSourceIn* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to the source bitmap.

*pIPalette* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

Pointer to the palette to use for encoding.

*pIFrameEncode* \[in\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\***

Pointer to the frame encode object.

*ppSourceOut* \[out\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\*\***

Pointer that receives a pointer to the output source.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll;

Wincodec.lib |