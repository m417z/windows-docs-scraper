# IWICMetadataBlockReader::GetReaderByIndex

## Description

Retrieves an [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader) for a specified top level metadata block.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index of the desired top level metadata block to retrieve.

### `ppIMetadataReader` [out]

Type: **[IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader)****

When this method returns, contains a pointer to the [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader) specified by *nIndex*.

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