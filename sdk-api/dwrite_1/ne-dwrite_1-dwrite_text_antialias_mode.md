# DWRITE_TEXT_ANTIALIAS_MODE enumeration

## Description

The **DWRITE_TEXT_ANTIALIAS_MODE** enumeration contains values that specify the type of antialiasing to use for text when the rendering mode calls for antialiasing.

## Constants

### `DWRITE_TEXT_ANTIALIAS_MODE_CLEARTYPE`

ClearType antialiasing computes coverage independently for the red, green, and blue color elements of each pixel. This allows for more detail than conventional antialiasing. However, because there is no one alpha value for each pixel, ClearType is not suitable for rendering text onto a transparent intermediate bitmap.

### `DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE`

Grayscale antialiasing computes one coverage value for each pixel. Because the alpha value of each pixel is well-defined, text can be rendered onto a transparent bitmap, which can then be composited with other content.

**Note** Grayscale rendering with [IDWriteBitmapRenderTarget1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritebitmaprendertarget1) uses premultiplied alpha.

## See also

[IDWriteBitmapRenderTarget1::GetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritebitmaprendertarget1-gettextantialiasmode)

[IDWriteBitmapRenderTarget1::SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritebitmaprendertarget1-settextantialiasmode)