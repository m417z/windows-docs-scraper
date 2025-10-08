# IWICBitmapCodecInfo\_GetFileExtensions\_Proxy function

Proxy function for the [**GetFileExtensions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapcodecinfo-getfileextensions) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo)\***

Pointer to this [**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo) object.

*cchFileExtensions* \[in\]

Type: **UINT**

The size of the file name extension buffer.

*wzFileExtensions* \[in, out\]

Type: **WCHAR\***

A pointer that receives the file name extensions associated with the codec.

*pcchActual* \[in, out\]

Type: **UINT\***

The actual buffer size needed to retrieve all file name extensions associated with the codec.

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

