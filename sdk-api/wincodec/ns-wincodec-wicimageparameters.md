# WICImageParameters structure

## Description

This defines parameters that you can use to override the default parameters normally used when encoding an image.

## Members

### `PixelFormat`

The pixel format to which the image is processed before it is written to the encoder.

### `DpiX`

The DPI in the x dimension.

### `DpiY`

The DPI in the y dimension.

### `Top`

The top corner in pixels of the image space to be encoded to the destination.

### `Left`

The left corner in pixels of the image space to be encoded to the destination.

### `PixelWidth`

The width in pixels of the part of the image to write.

### `PixelHeight`

The height in pixels of the part of the image to write.

## Remarks

If this parameter is not passed to the encoding API, the encoder uses these settings.

* A pixel format of ([DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), [D2D1_ALPHA_MODE_PREMULTIPLIED](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode)).
* An x and y DPI of 96.
* The entire image bounds will be used for encoding.

**Note** The parameters as specified can't result in a scale. The encoder can use a larger portion of the input image based on the passed in DPI and the pixel width and height.

## See also

[IWICImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimageencoder)