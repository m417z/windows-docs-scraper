# IWICPalette\_InitializePredefined\_Proxy function

Proxy function for the [**InitializePredefined**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpalette-initializepredefined) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

Pointer to this [**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette) object.

*ePaletteType* \[in\]

Type: **[**WICBitmapPaletteType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmappalettetype)**

The desired pre-defined palette type.

*fAddTransparentColor* \[in\]

Type: **BOOL**

The optional tranparent color to add to the palette. If no transparent color is needed, use 0.

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

