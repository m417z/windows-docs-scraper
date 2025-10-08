# IWICBitmapEncoder\_GetEncoderInfo\_Proxy function

Proxy function for the [**GetEncoderInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapencoder-getencoderinfo) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)\***

Pointer to this [**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) object.

*ppIEncoderInfo* \[out\]

Type: **[**IWICBitmapEncoderInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapencoderinfo)\*\***

A pointer that receives a pointer to an [**IWICBitmapEncoderInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapencoderinfo).

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

