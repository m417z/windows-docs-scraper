# IDWriteFont::GetMetrics

## Description

 Obtains design units and common metrics for the font face.
These metrics are applicable to all the glyphs within a font face and are used by applications for layout calculations.

## Parameters

### `fontMetrics` [out]

Type: **[DWRITE_FONT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_metrics)***

When this method returns, contains a structure that has font metrics for the current font face. The metrics returned by this function are in font design units.

## See also

[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)