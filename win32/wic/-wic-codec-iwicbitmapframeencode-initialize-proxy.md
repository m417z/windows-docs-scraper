# IWICBitmapFrameEncode\_Initialize\_Proxy function

Proxy function for the [**Initialize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapframeencode-initialize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\***

Pointer to this [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode) object.

*pIEncoderOptions* \[in\]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))\***

The set of properties to use for [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode) initialization.

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