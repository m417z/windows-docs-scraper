# DWRITE_OUTLINE_THRESHOLD enumeration

## Description

The **DWRITE_OUTLINE_THRESHOLD** enumeration contains values that specify the policy used by the [IDWriteFontFace1::GetRecommendedRenderingMode](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getrecommendedrenderingmode) method to determine whether to render glyphs in outline mode.

## Constants

### `DWRITE_OUTLINE_THRESHOLD_ANTIALIASED`

Graphics system renders anti-aliased outlines.

### `DWRITE_OUTLINE_THRESHOLD_ALIASED`

Graphics system renders aliased outlines.

## Remarks

Glyphs are rendered in outline mode by default at large sizes for performance reasons, but how large (that is, the outline threshold) depends on the quality of outline rendering. If the graphics system renders anti-aliased outlines, a relatively low threshold is used. But if the graphics system renders aliased outlines, a much higher threshold is used.

## See also

[IDWriteFontFace1::GetRecommendedRenderingMode](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getrecommendedrenderingmode)