# IWICImagingFactory\_CreateBitmapFlipRotator\_Proxy function

Proxy function for the [**CreateBitmapFlipRotator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createbitmapfliprotator) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*ppIBitmapFlipRotator* \[out\]

Type: **[**IWICBitmapFlipRotator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapfliprotator)\*\***

A pointer that receives a pointer to a new [**IWICBitmapFlipRotator**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapfliprotator).

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