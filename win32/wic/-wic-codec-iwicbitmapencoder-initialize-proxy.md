# IWICBitmapEncoder\_Initialize\_Proxy function

Proxy function for the [**Initialize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapencoder-initialize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)\***

Pointer to this [**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) object.

*pIStream* \[in\]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)\***

The output stream.

*cacheOption* \[in\]

Type: **[**WICBitmapEncoderCacheOption**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapencodercacheoption)**

The [**WICBitmapEncoderCacheOption**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapencodercacheoption) used on initialization.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll; <br>Wincodec.lib |

