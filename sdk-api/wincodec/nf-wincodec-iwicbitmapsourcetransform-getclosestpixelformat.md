# IWICBitmapSourceTransform::GetClosestPixelFormat

## Description

Retrieves the closest pixel format to which the implementation of [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsourcetransform) can natively copy pixels, given a desired format.

## Parameters

### `pguidDstFormat` [in, out]

Type: **WICPixelFormatGUID***

A pointer that receives the GUID of the pixel format that is the closest supported pixel format of the desired format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Windows provided codecs provide the following support:

* BMP, ICO, GIF, TIFF: No implementation of [IWICBitmapSourceTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsourcetransform).
* JPEG, PNG, JPEG-XR: Trivial support (always returns the same value as [IWICBitmapFrameDecode::GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-getpixelformat)).