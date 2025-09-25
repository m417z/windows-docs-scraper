# IWICMetadataBlockWriter::SetWriterByIndex

## Description

Replaces the metadata writer at the specified index location.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index position at which to place the metadata writer. This index is zero-based.

### `pIMetadataWriter` [in]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)***

A pointer to the [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Typically, the current metadata writer at the specified index will be replaced with the new writer. However, the App0 metadata writer cannot be replaced within a JPEG stream.

This function cannot be used to add metadata writers. If no metadata writer exists at the specified index, the function will fail.

## See also

**Conceptual**

[How to Write a WIC-Enabled CODEC](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec)

[How-to: Re-encode a JPEG Image with Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-jpegmetadataencoding)

[IWICMetadataBlockWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter)

**Other Resources**

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)