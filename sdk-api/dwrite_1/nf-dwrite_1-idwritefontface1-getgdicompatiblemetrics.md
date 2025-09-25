# IDWriteFontFace1::GetGdiCompatibleMetrics

## Description

Obtains design units and common metrics for the font face.
These metrics are applicable to all the glyphs within a fontface and are used by applications for layout calculations.

## Parameters

### `emSize`

Type: **FLOAT**

The logical size of the font in DIP units.

### `pixelsPerDip`

Type: **FLOAT**

The number of physical pixels per DIP.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

An optional transform applied to the glyphs and their positions. This transform is applied after the scaling specified by the font size and *pixelsPerDip*.

### `fontMetrics` [out]

Type: **[DWRITE_FONT_METRICS1](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_font_metrics1)***

A pointer to a [DWRITE_FONT_METRICS1](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_font_metrics1) structure to fill in. The metrics returned by this function are in font design units.

## Return value

Type: **HRESULT**

Standard HRESULT error code.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)