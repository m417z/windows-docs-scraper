# IWICMetadataBlockWriter::GetWriterByIndex

## Description

Retrieves the [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter) that resides at the specified index.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index of the metadata writer to be retrieved. This index is zero-based.

### `ppIMetadataWriter` [out]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)****

When this method returns, contains a pointer to the metadata writer that resides at the specified index.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[How to Write a WIC-Enabled CODEC](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec)

[How-to: Re-encode a JPEG Image with Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-jpegmetadataencoding)

[IWICMetadataBlockWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter)

**Other Resources**

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)