# IWICPalette\_InitializeFromBitmap\_Proxy function

Proxy function for the [**InitializeFromBitmap**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicpalette-initializefrombitmap) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

Pointer to this [**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette) object.

*pISurface* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

Pointer to the source bitmap.

*colorCount* \[in\]

Type: **UINT**

The number of colors to initialize the palette with.

*fAddTransparentColor* \[in\]

Type: **BOOL**

A value to indicate whether to add a transparent color.

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