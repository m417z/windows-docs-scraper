# IWICBitmapFrameEncode\_SetColorContexts\_Proxy function

Proxy function for the [**SetColorContexts**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapframeencode-setcolorcontexts) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\***

Pointer to this [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode) object.

*cCount* \[in\]

Type: **UINT**

The number of [**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext) profiles to set.

*ppIColorContext* \[in\]

Type: **[**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext)\*\***

A pointer to an [**IWICColorContext**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwiccolorcontext) pointer containing the color contexts profiles to set to the frame.

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

