# IWICBitmapEncoder::Commit

## Description

Commits all changes for the image and closes the stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To finalize an image, both the frame [Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-commit) and the encoder **Commit** must be called. However, only call the encoder **Commit** method after all frames have been committed.

After the encoder has been committed, it can't be re-initialized or reused with another stream. A new encoder interface must be created, for example, with [IWICImagingFactory::CreateEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createencoder).

For the encoder **Commit** to succeed, you must at a minimum call [IWICBitmapEncoder::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapdecoder-initialize) and either [IWICBitmapFrameEncode::WriteSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writesource) or [IWICBitmapFrameEncode::WritePixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writepixels).

[IWICBitmapFrameEncode::WriteSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writesource) specifies all parameters needed to encode the image data. [IWICBitmapFrameEncode::WritePixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writepixels) requires that you also call [IWICBitmapFrameEncode::SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize), [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat), and [IWICBitmapFrameEncode::SetPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpalette) (if the pixel format is indexed).

## See also

[Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-commit)

[IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)