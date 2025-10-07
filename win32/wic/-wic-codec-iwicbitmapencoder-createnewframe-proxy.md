# IWICBitmapEncoder\_CreateNewFrame\_Proxy function

Proxy function for the [**CreateNewFrame**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapencoder-createnewframe) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)\***

Pointer to this [**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) object.

*ppIFrameEncode* \[out\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\*\***

A pointer that receives a pointer to the new instance of an [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode).

*ppIEncoderOptions* \[in, out\]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))\*\***

The named properties to use for frame initialization.

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