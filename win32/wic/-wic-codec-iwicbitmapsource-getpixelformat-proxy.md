# IWICBitmapSource\_GetPixelFormat\_Proxy function

Proxy function for the [**GetPixelFormat**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapsource-getpixelformat) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to this [**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource) object.

*pPixelFormat* \[out\]

Type: **WICPixelFormatGUID\***

A pointer that receives the pixel format GUID the bitmap is stored in.

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

