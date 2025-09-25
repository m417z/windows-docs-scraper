# IWICPlanarBitmapSourceTransform::CopyPixels

## Description

Copies pixels into the destination planes. Configured by the supplied input parameters.

If a *dstTransform*, scale, or format conversion is specified, *cbStride* is the transformed stride and is based on the destination pixel format of the *pDstPlanes* parameter, not the original source's pixel format.

## Parameters

### `prcSource` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The source rectangle of pixels to copy.

### `uiWidth`

Type: **UINT**

The width to scale the source bitmap. This parameter must be equal to a value obtainable through [IWICPlanarBitmapSourceTransform:: DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform).

### `uiHeight`

Type: **UINT**

The height to scale the source bitmap. This parameter must be equal to a value obtainable through [IWICPlanarBitmapSourceTransform:: DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform).

### `dstTransform`

Type: **[WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions)**

The desired rotation or flip to perform prior to the pixel copy. A rotate can be combined with a flip horizontal or a flip vertical, see [WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions).

### `dstPlanarOptions` [in]

Type: **const [WICPlanarOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions)**

Used to specify additional configuration options for the transform. See [WICPlanarOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions) for more detail.

WIC JPEG Decoder:
[WICPlanarOptionsPreserveSubsampling](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicplanaroptions) can be specified to retain the subsampling ratios when downscaling. By default, the JPEG decoder attempts to preserve quality by downscaling only the Y plane in some cases, changing the image to 4:4:4 chroma subsampling.

### `pDstPlanes`

Type: **[WICBitmapPlane](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmapplane)**

Specifies the pixel format and output buffer for each component plane. The number of planes and pixel format of each plane must match values obtainable through [IWICPlanarBitmapSourceTransform::DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform).

### `cPlanes`

Type: **UINT**

The number of component planes specified by the *pDstPlanes* parameter.

## Return value

Type: **HRESULT**

If the specified scale, flip/rotate, and planar format configuration is not supported this method fails with **WINCODEC_ERR_INVALIDPARAMETER**. You can check if a transform is supported by calling [IWICPlanarBitmapSourceTransform::DoesSupportTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapsourcetransform-doessupporttransform).

## Remarks

WIC JPEG Decoder:
Depending on the configured chroma subsampling of the image, the source rectangle has the following restrictions:

| Chroma Subsampling | X Coordinate | Y Coordinate | Chroma Width | Chroma Height |
| --- | --- | --- | --- | --- |
| 4:2:0 | Multiple of 2 | Multiple of 2 | lumaWidth / 2 Rounded up to the nearest integer. | lumaHeight / 2 Rounded up to the nearest integer. |
| 4:2:2 | Multiple of 2 | Any | lumaWidth / 2 Rounded up to the nearest integer. | lumaHeight |
| 4:4:4 | Any | Any | llumaWidth | llumaHeight |
| 4:4:0 | Any | Multiple of 2 | lumaWidth | llumaHeight / 2 Rounded up to the nearest integer. |

The *pDstPlanes* parameter supports the following pixel formats.

| Plane Count | Plane 1 | Plane 2 | Plane 3 |
| --- | --- | --- | --- |
| 3 | GUID_WICPixelFormat8bppY | GUID_WICPixelFormat8bppCb | GUID_WICPixelFormat8bppCr |
| 2 | GUID_WICPixelFormat8bppY | GUID_WICPixelFormat16bppCbCr | N/A |

## See also

[IWICPlanarBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarbitmapsourcetransform)