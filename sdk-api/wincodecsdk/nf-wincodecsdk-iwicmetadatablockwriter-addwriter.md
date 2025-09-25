# IWICMetadataBlockWriter::AddWriter

## Description

Adds a top-level metadata block by adding a [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter) for it.

## Parameters

### `pIMetadataWriter` [in]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)***

A pointer to the metadata writer to add to the image.

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