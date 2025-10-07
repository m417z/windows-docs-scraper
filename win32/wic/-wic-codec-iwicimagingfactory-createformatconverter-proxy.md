# IWICImagingFactory\_CreateFormatConverter\_Proxy function

Proxy function for the [**CreateFormatConverter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createformatconverter) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*ppIFormatConverter* \[out\]

Type: **[**IWICFormatConverter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicformatconverter)\*\***

A pointer that receives a pointer to a new [**IWICFormatConverter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicformatconverter).

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