# IWICImagingFactory::CreateQueryWriter

## Description

Creates a new instance of a query writer.

## Parameters

### `guidMetadataFormat` [in]

Type: **REFGUID**

The GUID for the desired metadata format.

### `pguidVendor` [in]

Type: **const GUID***

The GUID for the preferred metadata writer vendor. Use **NULL** if no preferred vendor.

### `ppIQueryWriter` [out]

Type: **[IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter)****

When this method returns, contains a pointer to a new [IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC GUIDs and CLSIDs](https://learn.microsoft.com/windows/desktop/wic/-wic-guids-clsids)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)