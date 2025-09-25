# IWICBitmapSourceTransform::DoesSupportTransform

## Description

Determines whether a specific transform option is supported natively by the implementation of the [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsourcetransform) interface.

## Parameters

### `dstTransform` [in]

Type: **[WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions)**

The [WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions) to check if they are supported.

### `pfIsSupported` [out]

Type: **BOOL***

A pointer that receives a value specifying whether the transform option is supported.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Windows provided codecs provide the following level of support:

* BMP, ICO, GIF, TIFF: No implementation of [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapsourcetransform).
* JPEG, PNG: Trivial support (WICBitmapTransformRotate0 only).
* JPEG-XR: Support for all transformation/rotations.