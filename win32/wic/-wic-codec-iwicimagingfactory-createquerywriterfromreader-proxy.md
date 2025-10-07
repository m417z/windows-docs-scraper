# IWICImagingFactory\_CreateQueryWriterFromReader\_Proxy function

Proxy function for the [**CreateQueryWriterFromReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createquerywriterfromreader) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*pIQueryReader* \[in\]

Type: **[**IWICMetadataQueryReader**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataqueryreader)\***

The metadata query reader to create the metadata writer from.

*pguidVendor* \[in\]

Type: **const GUID\***

The vendor GUID for the metadata query writer.

*ppIQueryWriter* \[out\]

Type: **[**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter)\*\***

A pointer that receives a pointer to a new [**IWICMetadataQueryWriter**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicmetadataquerywriter).

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