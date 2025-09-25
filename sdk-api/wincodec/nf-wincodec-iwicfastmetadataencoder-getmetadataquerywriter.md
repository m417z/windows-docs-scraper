# IWICFastMetadataEncoder::GetMetadataQueryWriter

## Description

Retrieves a metadata query writer for fast metadata encoding.

## Parameters

### `ppIMetadataQueryWriter` [out]

Type: **[IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter)****

When this method returns, contains a pointer to the fast metadata encoder's metadata query writer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[IWICFastMetadataEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicfastmetadataencoder)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)