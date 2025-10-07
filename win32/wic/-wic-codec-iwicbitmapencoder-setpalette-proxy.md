# IWICBitmapEncoder\_SetPalette\_Proxy function

Proxy function for the [**SetPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicbitmapencoder-setpalette) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)\***

Pointer to this [**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) object.

*pIPalette* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

The [**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette) to use as the global palette.

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