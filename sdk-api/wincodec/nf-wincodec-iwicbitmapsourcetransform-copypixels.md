# IWICBitmapSourceTransform::CopyPixels

## Description

Copies pixel data using the supplied input parameters.

## Parameters

### `prc` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/win32/api/wincodec/ns-wincodec-wicrect)***

The rectangle of pixels to copy.

### `uiWidth` [in]

Type: **UINT**

The width to scale the source bitmap. This parameter must equal the value obtainable through [IWICBitmapSourceTransform::GetClosestSize](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicbitmapsourcetransform-getclosestsize).

### `uiHeight` [in]

Type: **UINT**

The height to scale the source bitmap. This parameter must equal the value obtainable through [IWICBitmapSourceTransform::GetClosestSize](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicbitmapsourcetransform-getclosestsize).

### `pguidDstFormat` [in]

Type: **WICPixelFormatGUID***

The GUID of desired pixel format in which the pixels should be returned.

This GUID must be a format obtained through an [GetClosestPixelFormat](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicbitmapsourcetransform-getclosestpixelformat) call.

### `dstTransform` [in]

Type: **[WICBitmapTransformOptions](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmaptransformoptions)**

The desired rotation or flip to perform prior to the pixel copy.

The transform must be an operation supported by an [DoesSupportTransform](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicbitmapsourcetransform-doessupporttransform) call.

If a *dstTransform* is specified, *nStride* is the *transformed stride* and is based on the *pguidDstFormat* pixel format, not the original source's pixel format.

### `nStride` [in]

Type: **UINT**

The stride of the destination buffer.

### `cbBufferSize` [in]

Type: **UINT**

The size of the destination buffer.

### `pbBuffer` [out]

Type: **BYTE***

The output buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### Codec Developer Remarks

If NULL is passed in for *prc*, the entire image is copied.

For codec developer implementation details for this method, see [Implementing IWICBitmapSourceTransform](https://learn.microsoft.com/windows/win32/wic/-wic-imp-iwicbitmapsourcetransform).

When multiple transform operations are requested, the result is dependent on the order in which the operations are performed.
To ensure predictability and consistency across CODECs, it's important that all CODECs perform these operations in the same order.
The recommended order of these operations is:

1. Scale
2. Crop
3. Flip/Rotate

Pixel format conversion can be performed at any time, since it has no effect on the other transforms.

The first parameter, *prc* is used to specify the region of interest for clipping the image.
By convention, scaling is performed before clipping so, if the image is to be scaled as well as clipped, the region of interest should be determined after the image has been scaled.

If a *dstTransform* is specified, the stride is the transformed stride, and is based on the pixelFormat specified in the **CopyPixels** call, not the original frame's pixel format.

## See also

**Conceptual**

[IWICBitmapSourceTransform](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmapsourcetransform)

[Microsoft Windows Imaging Codec](https://learn.microsoft.com/windows/win32/wic/-wic-lh)

[Programming Guide](https://learn.microsoft.com/windows/win32/wic/-wic-programming-guide)

[References](https://learn.microsoft.com/windows/win32/wic/-wic-codec-reference)

[Samples and Code Examples](https://learn.microsoft.com/windows/win32/wic/-wic-samples)