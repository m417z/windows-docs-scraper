# IWICPixelFormatInfo\_GetChannelCount\_Proxy function

Proxy function for the [**GetChannelCount**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpixelformatinfo-getchannelcount) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPixelFormatInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpixelformatinfo)\***

Pointer to this [**IWICPixelFormatInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpixelformatinfo) object.

*puiChannelCount* \[out\]

Type: **UINT\***

Pointer that receives the channel count.

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