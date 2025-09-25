# IDWriteRenderingParams::GetRenderingMode

## Description

Gets the rendering mode of the rendering parameters object.

## Return value

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)**

A value that indicates the rendering mode of the rendering parameters object.

## Remarks

By default, the rendering mode is initialized to DWRITE_RENDERING_MODE_DEFAULT, which means the rendering mode is determined automatically based on the font and size. To determine the recommended rendering mode to use for a given font and size and rendering parameters object, use the [IDWriteFontFace::GetRecommendedRenderingMode](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getrecommendedrenderingmode) method.

## See also

[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)