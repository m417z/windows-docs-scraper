# IWICMetadataBlockReader::GetEnumerator

## Description

Retrieves an enumeration of [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader) objects representing each of the top level metadata blocks.

## Parameters

### `ppIEnumMetadata` [out]

Type: **[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)****

When this method returns, contains a pointer to an enumeration of [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader) objects.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[How to Write a WIC-Enabled CODEC](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec)

[IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader)

**Other Resources**

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)

[Windows Imaging Component Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-windows-imaging-codec)