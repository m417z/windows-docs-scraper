# IWICMetadataBlockWriter::InitializeFromBlockReader

## Description

Initializes an [IWICMetadataBlockWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter) from the given [IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader). This will prepopulate the metadata block writer with all the metadata in the metadata block reader.

## Parameters

### `pIMDBlockReader` [in]

Type: **[IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader)***

Pointer to the [IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader) used to initialize the block writer.

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