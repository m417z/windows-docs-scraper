# IWICBitmapSource\_GetResolution\_Proxy function

Proxy function for the [**GetResolution**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapsource-getresolution) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to this [**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource) object.

*pDpiX* \[out\]

Type: **double\***

A pointer that receives the x-axis dpi resolution.

*pDpiY* \[out\]

Type: **double\***

A pointer that receives the y-axis dpi resolution.

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

