# IWICMetadataQueryReader::GetEnumerator

## Description

Gets an enumerator of all metadata items at the current relative location within the metadata hierarchy.

## Parameters

### `ppIEnumString` [out]

Type: **[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)****

A pointer to a variable that receives a pointer to the [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface for the enumerator that contains query strings that can be used in the current [IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The retrieved enumerator only contains query strings for the metadata blocks and items in the current level of the hierarchy.

## See also

**Conceptual**

[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)