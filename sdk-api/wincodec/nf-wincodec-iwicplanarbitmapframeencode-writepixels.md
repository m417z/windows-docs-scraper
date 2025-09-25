# IWICPlanarBitmapFrameEncode::WritePixels

## Description

Writes lines from the source planes to the encoded format.

## Parameters

### `lineCount`

Type: **UINT**

The number of lines to encode. See the Remarks section for WIC Jpeg specific line count restrictions.

### `pPlanes` [in]

Type: **[WICBitmapPlane](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmapplane)***

Specifies the source buffers for each component plane encoded.

### `cPlanes`

Type: **UINT**

The number of component planes specified by the *pPlanes* parameter.

## Return value

Type: **HRESULT**

If the planes and source rectangle do not meet the requirements, this method fails with **WINCODEC_ERR_IMAGESIZEOUTOFRANGE**.

If the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) format does not meet the encoder requirements, this method fails with **WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT**.

## Remarks

Successive **WritePixels** calls are assumed sequentially add scanlines to the output image. [IWICBitmapFrameEncode::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarformatconverter-initialize), [IWICBitmapFrameEncode::SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize) and [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat) must be called before this method or it will fail.

The interleaved pixel format set via [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat) and the codec specific encode parameters determine the supported planar formats.

WIC JPEG Encoder:
QueryInterface can be used to obtain this interface from the WIC JPEG [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) implementation. When using this method to encode Y’CbCr data with the WIC JPEG encoder, chroma subsampling can be configured with encoder options during frame creation. See the [Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder) and [IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe) for more details.

Depending upon the configured chroma subsampling, the lineCount parameter has the following restrictions:

| Chroma Subsampling | Line Count Restriction | Chroma Plane Width | Chroma Plane Height |
| --- | --- | --- | --- |
| 4:2:0 | Multiple of 2, unless the call covers the last scanline of the image | lumaWidth / 2 Rounded up to the nearest integer. | lumaHeight / 2 Rounded up to the nearest integer. |
| 4:2:2 | Any | lumaWidth / 2 Rounded up to the nearest integer. | Any |
| 4:4:4 | Any | Any | Any |
| 4:4:0 | Multiple of 2, unless the call covers the last scanline of the image | Any | llumaHeight / 2 Rounded up to the nearest integer. |

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