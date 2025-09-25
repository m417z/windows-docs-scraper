# IWICBitmapFrameEncode::SetThumbnail

## Description

Sets the frame thumbnail if supported by the codec.

## Parameters

### `pIThumbnail` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The bitmap source to use as the thumbnail.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

Returns WINCODEC_ERR_UNSUPPORTEDOPERATION if the feature is not supported by the encoder.

## Remarks

We recommend that you call
**SetThumbnail** before calling [WritePixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writepixels) or [WriteSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writesource).
The thumbnail won't be added to the encoded file if **SetThumbnail** is called after a call to **WritePixels** or **WriteSource**.

* **BMP, PNG**Setting thumbnails is unsupported. This function will return **WINCODEC_ERR_UNSUPPORTEDOPERATION**.
* **JPEG**Setting the thumbnail is supported. The source image will be re-encoded as either an 8bpp or 24bpp JPEG and will be written to the JPEG’s APP1 metadata block.
* **TIFF** Setting the thumbnail is supported. The source image will be re-encoded as a TIFF and will be written to the frame’s SubIFD block.
* **JPEG-XR**Setting the thumbnail is supported. The source image will be re-encoded as an additional 8bpp or 24bpp frame.

## See also

**Conceptual**

[Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder)

[How to Write a WIC-Enabled CODEC](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec)

[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)