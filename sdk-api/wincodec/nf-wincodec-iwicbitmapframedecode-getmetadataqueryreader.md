# IWICBitmapFrameDecode::GetMetadataQueryReader

## Description

Retrieves a metadata query reader for the frame.

## Parameters

### `ppIMetadataQueryReader` [out]

Type: **[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)****

When this method returns, contains a pointer to the frame's metadata query reader.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For image formats with one frame (JPG, PNG, JPEG-XR), the frame-level query reader of the first frame is used to access all image metadata, and the decoder-level query reader isn’t used. For formats with more than one frame (GIF, TIFF), the frame-level query reader for a given frame is used to access metadata specific to that frame, and in the case of GIF a decoder-level metadata reader will be present. If the decoder doesn’t support metadata (BMP, ICO), this will return [WINCODEC_ERR_UNSUPPORTEDOPERATION](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-error-codes).

## See also

**Conceptual**

[IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)