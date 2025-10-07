# IWICImagingFactory\_CreateBitmapFromHBITMAP\_Proxy function

Proxy function for the [**CreateBitmapFromHBITMAP**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createbitmapfromhbitmap) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*hBitmap* \[in\]

Type: **HBITMAP**

A bitmap handle to create the bitmap from.

*hPalette* \[in\]

Type: **HPALETTE**

A palette handle used to create the bitmap.

*options* \[in\]

Type: **[**WICBitmapAlphaChannelOption**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapalphachanneloption)**

The alpha channel options to create the bitmap.

*ppIBitmap* \[out\]

Type: **[**IWICBitmap**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmap)\*\***

A pointer that receives a pointer to the new bitmap.

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