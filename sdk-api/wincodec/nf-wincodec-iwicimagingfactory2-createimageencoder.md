# IWICImagingFactory2::CreateImageEncoder

## Description

Creates a new image encoder object.

## Parameters

### `pD2DDevice` [in]

The [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) object on which the corresponding image encoder is created.

### `ppWICImageEncoder` [out]

A pointer to a variable that receives a pointer to the [IWICImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimageencoder) interface for the encoder object that you can use to encode [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) images.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must create images to pass to the image encoder on the same [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) device that you pass to this method.

You are responsible for setting up the bitmap encoder itself through the existing [IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapencoder) APIs. The **IWICBitmapEncoder** or the [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapframeencode) object is passed to each of the [IWICImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimageencoder) methods: [WriteThumbnail](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimageencoder-writethumbnail), [WriteFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimageencoder-writeframe), and [WriteFrameThumbnail](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimageencoder-writeframethumbnail).

## See also

[IWICImagingFactory2](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory2)