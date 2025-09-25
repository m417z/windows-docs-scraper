# IWICBitmapDecoder::GetMetadataQueryReader

## Description

Retrieves the metadata query reader from the decoder.

## Parameters

### `ppIMetadataQueryReader` [out]

Type: **[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)****

Receives a pointer to the decoder's [IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If an image format does not support container-level metadata, this will return [WINCODEC_ERR_UNSUPPORTEDOPERATION](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-error-codes). The only Windows provided image format that supports container-level metadata is GIF. Instead, use [IWICBitmapFrameDecode::GetMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframedecode-getmetadataqueryreader).

## See also

**Conceptual**

[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)