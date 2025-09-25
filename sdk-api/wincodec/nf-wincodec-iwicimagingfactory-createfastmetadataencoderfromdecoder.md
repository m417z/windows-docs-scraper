# IWICImagingFactory::CreateFastMetadataEncoderFromDecoder

## Description

Creates a new instance of the fast metadata encoder based on the given [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder).

## Parameters

### `pIDecoder` [in]

Type: **[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)***

The decoder to create the fast metadata encoder from.

### `ppIFastEncoder` [out]

Type: **[IWICFastMetadataEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicfastmetadataencoder)****

When this method returns, contains a pointer to the new [IWICFastMetadataEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicfastmetadataencoder).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Windows provided codecs do not support fast metadata encoding at the decoder level, and only support fast metadata encoding at the frame level. To create a fast metadata encoder from a frame, see [CreateFastMetadataEncoderFromFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createfastmetadataencoderfromframedecode).

## See also

**Conceptual**

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)