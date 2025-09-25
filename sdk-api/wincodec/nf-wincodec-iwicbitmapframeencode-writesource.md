# IWICBitmapFrameEncode::WriteSource

## Description

Encodes a bitmap source.

## Parameters

### `pIBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The bitmap source to encode.

### `prc` [in]

Type: **[WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The size rectangle of the bitmap source.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If [SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize) is not called prior to calling **WriteSource**, the size given in *prc* is used if not **NULL**. Otherwise, the size of the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) given in *pIBitmapSource* is used.

If [SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat) is not called prior to calling **WriteSource**, the pixel format of the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) given in *pIBitmapSource* is used.

If [SetResolution](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setresolution) is not called prior to calling **WriteSource**, the pixel format of *pIBitmapSource* is used.

If [SetPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpalette) is not called prior to calling **WriteSource**, the target pixel format is indexed, and the pixel format of *pIBitmapSource* matches the encoder frame's pixel format, then the *pIBitmapSource* pixel format is used.

When encoding a GIF image, if the global palette is set and the frame level palette is not set directly by the user or by a custom independent software vendor (ISV) GIF codec, **WriteSource** will use the global palette to encode the frame even when *pIBitmapSource* has a frame level palette.

Starting with Windows Vista, repeated **WriteSource** calls can be made as long as the total accumulated source rect height is the same as set through [SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize).

Starting with Windows 8.1, the source rect must be at least the dimensions set through [SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize). If the source rect width exceeds the **SetSize** width, extra pixels on the right side are ignored. If the source rect height exceeds the remaining unfilled height, extra scan lines on the bottom are ignored.

## See also

**Conceptual**

[How to Write a WIC-Enabled CODEC](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec)

[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)

[Windows Imaging Component Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-windows-imaging-codec)