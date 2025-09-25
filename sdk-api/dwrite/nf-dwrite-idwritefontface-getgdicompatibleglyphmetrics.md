# IDWriteFontFace::GetGdiCompatibleGlyphMetrics

## Description

Obtains glyph metrics in font design units with the return values compatible with what GDI would produce.

## Parameters

### `emSize`

Type: **FLOAT**

The logical size of the font in DIP units.

### `pixelsPerDip`

Type: **FLOAT**

The number of physical pixels per DIP.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

An optional transform applied to the glyphs and their positions. This transform is applied after the
scaling specified by the font size and *pixelsPerDip*.

### `useGdiNatural`

Type: **BOOL**

When set to **FALSE**, the metrics are the same as the metrics of GDI aliased text. When set to **TRUE**, the metrics are the same as the metrics of text measured by GDI using a font created with **CLEARTYPE_NATURAL_QUALITY**.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph indices for which to compute the metrics.

### `glyphCount`

Type: **UINT32**

The number of elements in the *glyphIndices* array.

### `glyphMetrics` [out]

Type: **[DWRITE_GLYPH_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_metrics)***

An array of [DWRITE_GLYPH_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_metrics) structures filled by this function. The metrics are in font design units.

### `isSideways`

Type: **BOOL**

A BOOL value that indicates whether the font is being used in a sideways run. This can affect the glyph metrics if the font has oblique simulation because sideways oblique simulation differs from non-sideways oblique simulation.

## Return value

Type: **HRESULT**

Standard **HRESULT** error code. If any of the input glyph indices are outside of the valid glyph index range for the current font face, **E_INVALIDARG** will be returned.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)