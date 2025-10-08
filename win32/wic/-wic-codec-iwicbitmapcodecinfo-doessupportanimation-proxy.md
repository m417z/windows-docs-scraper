# IWICBitmapCodecInfo\_DoesSupportAnimation\_Proxy function

Proxy function for the [**DoesSupportAnimation**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapcodecinfo-doessupportanimation) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo)\***

Pointer to this [**IWICBitmapCodecInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapcodecinfo) object.

*pfSupportAnimation* \[out\]

Type: **BOOL\***

A pointer that receives **TRUE** if the codec supports images with timing information; otherwise, **FALSE**.

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

