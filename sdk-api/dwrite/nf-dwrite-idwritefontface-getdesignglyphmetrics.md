# IDWriteFontFace::GetDesignGlyphMetrics

## Description

 Obtains ideal (resolution-independent) glyph metrics in font design units.

## Parameters

### `glyphIndices` [in]

Type: **const UINT16***

 An array of glyph indices for which to compute metrics. The array must contain at least as many elements as specified by *glyphCount*.

### `glyphCount`

Type: **UINT32**

The number of elements in the *glyphIndices* array.

### `glyphMetrics` [out]

Type: **[DWRITE_GLYPH_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_metrics)***

When this method returns, contains an array of DWRITE_GLYPH_METRICS structures. *glyphMetrics* must be initialized with an empty buffer that contains at least as many elements as *glyphCount*.
The metrics returned by this function are in font design units.

### `isSideways`

Type: **BOOL**

Indicates whether the font is being used in a sideways run. This can affect the glyph metrics if the font has oblique simulation
because sideways oblique simulation differs from non-sideways oblique simulation

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Design glyph metrics are used for glyph positioning.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)