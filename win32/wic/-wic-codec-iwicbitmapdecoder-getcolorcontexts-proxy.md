# IWICBitmapDecoder\_GetColorContexts\_Proxy function

Proxy function for the [**GetColorContexts**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapdecoder-getcolorcontexts) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\***

Pointer to this [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder) object.

*cCount* \[in\]

Type: **UINT**

The number of color contexts to retrieve.

This value must be the size of, or smaller than, the size available to *ppIColorContexts*.

*ppIColorContexts* \[in, out\]

Type: **[**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext)\*\***

A pointer that receives a pointer to the [**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext).

*pcActualCount* \[out\]

Type: **UINT\***

A pointer that receives the number of color contexts contained in the image.

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

