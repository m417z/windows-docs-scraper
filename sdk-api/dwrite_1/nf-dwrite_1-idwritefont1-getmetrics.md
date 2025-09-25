# IDWriteFont1::GetMetrics

## Description

 Obtains design units and common metrics for the font face.
These metrics are applicable to all the glyphs within a font face and are used by applications for layout calculations.

## Parameters

### `fontMetrics` [out]

Type: **[DWRITE_FONT_METRICS1](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_font_metrics1)***

 A filled [DWRITE_FONT_METRICS1](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_font_metrics1) structure that has font metrics for the current font face. The metrics returned by this method are in font design units.

## See also

[IDWriteFont1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefont1)