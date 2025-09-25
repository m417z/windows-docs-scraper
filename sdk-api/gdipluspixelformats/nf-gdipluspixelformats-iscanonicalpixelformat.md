# IsCanonicalPixelFormat function

## Description

The **IsCanonicalPixelFormat** method determines whether a specified pixel format is one of the canonical formats: [PixelFormat32bppARGB](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants) or [PixelFormat64bppARGB](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants).

## Parameters

### `pixfmt`

Type: **PixelFormat**

A [PixelFormat](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants) constant that specifies the pixel format to be tested.

## Return value

Type: **BOOL**

If the pixel format is [PixelFormat32bppARGB](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants) or **PixelFormat64bppARGB**, this method returns **TRUE**; otherwise, it returns **FALSE**.