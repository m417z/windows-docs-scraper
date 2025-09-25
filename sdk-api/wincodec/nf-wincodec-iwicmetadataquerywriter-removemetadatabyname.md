# IWICMetadataQueryWriter::RemoveMetadataByName

## Description

Removes a metadata item from a specific location using a metadata query expression.

## Parameters

### `wzName` [in]

Type: **LPCWSTR**

The name of the metadata item to remove.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**RemoveMetadataByName** uses metadata query expressions to remove metadata. For more information on the metadata query language, see the [Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage).

If the metadata item is a metadata block, it is removed from the metadata hierarchy.

## See also

**Conceptual**

[How-to: Re-encode a JPEG Image with Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-jpegmetadataencoding)

[IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)