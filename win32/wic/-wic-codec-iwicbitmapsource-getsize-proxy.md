# IWICBitmapSource\_GetSize\_Proxy function

Proxy function for the [**GetSize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapsource-getsize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to this [**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource) object.

*puiWidth* \[out\]

Type: **UINT\***

A pointer that receives the pixel width of the bitmap.

*puiHeight* \[out\]

Type: **UINT\***

A pointer that receives the pixel height of the bitmap

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