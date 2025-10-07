# IWICImagingFactory\_CreateEncoder\_Proxy function

Proxy function for the [**CreateEncoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createencoder) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*guidContainerFormat* \[in\]

Type: **REFGUID**

The GUID for the desired container format.

*pguidVendor* \[in, optional\]

Type: **const GUID\***

The vendor GUID for the encoder.

*ppIEncoder* \[out\]

Type: **[**IWICBitmapEncoder**](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)\*\***

A pointer that receives a pointer to a new [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder).

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