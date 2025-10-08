# IWICBitmap\_SetResolution\_Proxy function

Proxy function for the [**SetResolution**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmap-setresolution) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmap**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmap)\***

Pointer to this [**IWICBitmap**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmap) object.

*dpiX* \[in\]

Type: **double**

The horizontal resolution.

*dpiY* \[in\]

Type: **double**

The vertical resolution.

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

