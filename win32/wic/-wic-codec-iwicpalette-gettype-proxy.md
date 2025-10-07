# IWICPalette\_GetType\_Proxy function

Proxy function for the [**GetType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpalette-gettype) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

Pointer to this [**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette) object.

*pePaletteType* \[out\]

Type: **[**WICBitmapPaletteType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmappalettetype)\***

Pointer that receives the palette type of the bimtap.

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