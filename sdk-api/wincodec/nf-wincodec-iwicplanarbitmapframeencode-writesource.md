# IWICPlanarBitmapFrameEncode::WriteSource

## Description

Writes lines from the source planes to the encoded format.

## Parameters

### `ppPlanes` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

Specifies an array of [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) that represent image planes.

### `cPlanes`

Type: **UINT**

The number of component planes specified by the planes parameter.

### `prcSource`

Type: **WICRect***

The source rectangle of pixels to encode from the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) planes. Null indicates the entire source. The source rect width must match the width set through [SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize). Repeated **WriteSource** calls can be made as long as the total accumulated source rect height is the same as set through **SetSize**.

## Return value

Type: **HRESULT**

If the planes and source rectangle do not meet the requirements, this method fails with **WINCODEC_ERR_IMAGESIZEOUTOFRANGE**.

If the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) format does not meet the encoder requirements, this method fails with **WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT**.

## Remarks

Successive **WriteSource** calls are assumed sequentially add scanlines to the output image. [IWICBitmapFrameEncode::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarformatconverter-initialize), [IWICBitmapFrameEncode::SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize) and [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat) must be called before this method or it will fail.

The interleaved pixel format set via [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat) and the codec specific encode parameters determine the supported planar formats.

WIC JPEG Encoder:
QueryInterface can be used to obtain this interface from the WIC JPEG [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) implementation. When using this method to encode Y’CbCr data with the WIC JPEG encoder, chroma subsampling can be configured with encoder options during frame creation. See the [Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder) and [IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe) for more details.

Depending upon the configured chroma subsampling, the lineCount parameter has the following restrictions:

| Chroma Subsampling | X Coordinate | Y Coordinate | Chroma Width | Chroma Height |
| --- | --- | --- | --- | --- |
| 4:2:0 | Multiple of 2 | Multiple of 2 | lumaWidth / 2 Rounded up to the nearest integer. | lumaHeight / 2 Rounded up to the nearest integer. |
| 4:2:2 | Multiple of 2 | Any | lumaWidth / 2 Rounded up to the nearest integer. | Any |
| 4:4:4 | Any | Any | Any | Any |
| 4:4:0 | Any | Multiple of 2 | lumaWidth | llumaHeight / 2 Rounded up to the nearest integer. |

The full scanline width must be encoded, and the width of the bitmap sources must match their planar configuration.

Additionally, if a pixel format is set via [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat), it must be GUID_WICPixelFormat24bppBGR.

The supported pixel formats of the bitmap sources passed into this method are as follows:

| Plane Count | Plane 1 | Plane 2 | Plane 3 |
| --- | --- | --- | --- |
| 3 | GUID_WICPixelFormat8bppY | GUID_WICPixelFormat8bppCb | GUID_WICPixelFormat8bppCr |
| 2 | GUID_WICPixelFormat8bppY | GUID_WICPixelFormat16bppCbCr | N/A |

## See also

[Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder)

[IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe)

[IWICPlanarBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarbitmapframeencode)