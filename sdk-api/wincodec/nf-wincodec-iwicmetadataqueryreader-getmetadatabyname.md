# IWICMetadataQueryReader::GetMetadataByName

## Description

Retrieves the metadata block or item identified by a metadata query expression.

## Parameters

### `wzName` [in]

Type: **LPCWSTR**

The query expression to the requested metadata block or item.

### `pvarValue` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this method returns, contains the metadata block or item requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**GetMetadataByName** uses metadata query expressions to access embedded metadata. For more information on the metadata query language, see the [Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage).

If multiple blocks or items exist that are expressed by the same query expression, the first metadata block or item found will be returned.

## See also

**Conceptual**

[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

**Other Resources**

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)