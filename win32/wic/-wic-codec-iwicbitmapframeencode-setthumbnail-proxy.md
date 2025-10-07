# IWICBitmapFrameEncode\_SetThumbnail\_Proxy function

Proxy function for the [**SetThumbnail**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapframeencode-setthumbnail) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode)\***

Pointer to this [**IWICBitmapFrameEncode**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapframeencode) object.

*pIThumbnail* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

The bitmap source to use as the thumbnail.

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