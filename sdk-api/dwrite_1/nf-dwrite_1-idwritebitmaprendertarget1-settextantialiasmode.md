# IDWriteBitmapRenderTarget1::SetTextAntialiasMode

## Description

Sets the current text antialiasing mode of the bitmap render target.

## Parameters

### `antialiasMode`

Type: **[DWRITE_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode)**

A [DWRITE_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode)-typed value that specifies the antialiasing mode.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_INVALIDARG if the argument is not valid.

## Remarks

The antialiasing mode of a newly-created bitmap render target defaults to
[DWRITE_TEXT_ANTIALIAS_MODE_CLEARTYPE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode). An app can change the antialiasing
mode by calling **SetTextAntialiasMode**. For example, an app might specify
[DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode) for grayscale antialiasing when it renders text onto a transparent bitmap.

## See also

[IDWriteBitmapRenderTarget1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritebitmaprendertarget1)