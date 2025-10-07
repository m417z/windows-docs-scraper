# IWICPalette\_GetColors\_Proxy function

Proxy function for the [**GetColors**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpalette-getcolors) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

Pointer to this [**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette) object.

*colorCount* \[in\]

Type: **UINT**

The size of the *pColors* array.

*pColors* \[out\]

Type: **WICColor\***

Pointer that receives the colors of the palette.

*pcActualColors* \[out\]

Type: **UINT\***

The actual size needed to obtain the palette colors.

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