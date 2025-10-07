# IWICFormatConverter\_Initialize\_Proxy function

Proxy function for the [**Initialize**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicformatconverter-initialize) method.

## Parameters

*THIS\_PTR* \[in\]

Type: **[**IWICFormatConverter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicformatconverter)\***

Pointer to this [**IWICFormatConverter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicformatconverter) object.

*pISource* \[in\]

Type: **[**IWICBitmapSource**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapsource)\***

The input bitmap to convert

*dstFormat* \[in\]

Type: **REFWICPixelFormatGUID**

The destination pixel format GUID.

*dither* \[in\]

Type: **[**WICBitmapDitherType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapdithertype)**

The [**WICBitmapDitherType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmapdithertype) used for conversion.

*pIPalette* \[in\]

Type: **[**IWICPalette**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicpalette)\***

The palette to use for conversion.

*alphaThresholdPercent* \[in\]

Type: **double**

The alpha threshold to use for conversion.

*paletteTranslate* \[in\]

Type: **[**WICBitmapPaletteType**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicbitmappalettetype)**

The palette translation type to use for conversion.

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