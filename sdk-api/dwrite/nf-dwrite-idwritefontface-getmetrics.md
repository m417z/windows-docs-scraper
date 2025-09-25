# IDWriteFontFace::GetMetrics

## Description

 Obtains design units and common metrics for the font face.
These metrics are applicable to all the glyphs within a font face and are used by applications for layout calculations.

## Parameters

### `fontFaceMetrics` [out]

Type: **[DWRITE_FONT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_metrics)***

When this method returns, a [DWRITE_FONT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_metrics) structure that holds metrics (such as ascent, descent, or cap height) for the current font face element.
The metrics returned by this function are in font design units.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)