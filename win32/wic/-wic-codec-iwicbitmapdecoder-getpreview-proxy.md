# IWICBitmapDecoder\_GetPreview\_Proxy function

Proxy function for the [**GetPreview**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapdecoder-getpreview) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\***

Pointer to this [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder) object.

*ppIBitmapSource* \[out\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\*\***

A pointer that receives a pointer to the preview bitmap if supported.

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