# IWICImageEncoder::WriteFrameThumbnail

## Description

Encodes the image as a thumbnail to the frame given by the [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapframeencode).

## Parameters

### `pImage` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The Direct2D image that will be encoded.

### `pFrameEncode` [in]

Type: **[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapframeencode)***

The frame encoder on which the thumbnail is set.

### `pImageParameters` [in]

Type: **const [WICImageParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicimageparameters)***

Additional parameters to control encoding.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The image passed in must be created on the same device as in [IWICImagingFactory2::CreateImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory2-createimageencoder). If the *pImageParameters* are not specified, a set of useful defaults will be assumed, see [WICImageParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicimageparameters) for more info.

You must correctly and independently have set up the [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapframeencode) before calling this API.

## See also

[IWICImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimageencoder)