# IWICPixelFormatInfo\_GetChannelMask\_Proxy function

Proxy function for the [**GetChannelMask**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpixelformatinfo-getchannelmask) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPixelFormatInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpixelformatinfo)\***

Pointer to this [**IWICPixelFormatInfo**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpixelformatinfo) object.

*uiChannelIndex* \[in\]

Type: **UINT**

The index to the channel mask to retrieve.

*cbMaskBuffer* \[in\]

Type: **UINT**

The size of the *pbMaskBuffer* buffer.

*pbMaskBuffer* \[in, out\]

Type: **BYTE\***

Pointer to the mask buffer.

*pcbActual* \[out\]

Type: **UINT\***

The actual buffer size needed to obtain the channel mask.

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

