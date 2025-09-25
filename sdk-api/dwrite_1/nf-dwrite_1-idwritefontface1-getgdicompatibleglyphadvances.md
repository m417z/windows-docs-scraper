# IDWriteFontFace1::GetGdiCompatibleGlyphAdvances

## Description

Returns the pixel-aligned advances for a sequences of glyphs.

## Parameters

### `emSize`

Type: **FLOAT**

Logical size of the font in DIP units. A DIP
("device-independent pixel") equals 1/96 inch.

### `pixelsPerDip`

Type: **FLOAT**

Number of physical pixels per DIP. For
example, if the DPI of the rendering surface is 96 this value is
1.0f. If the DPI is 120, this value is 120.0f/96.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

Optional transform applied to the glyphs and
their positions. This transform is applied after the scaling
specified by the font size and pixelsPerDip.

### `useGdiNatural`

Type: **BOOL**

When FALSE, the metrics are the same as
GDI aliased text (DWRITE_MEASURING_MODE_GDI_CLASSIC). When TRUE,
the metrics are the same as those measured by GDI using a font
using CLEARTYPE_NATURAL_QUALITY (DWRITE_MEASURING_MODE_GDI_NATURAL).

### `isSideways`

Type: **BOOL**

Retrieve the glyph's vertical advances rather
than horizontal advances.

### `glyphCount`

Type: **UINT32**

Total glyphs to retrieve adjustments for.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph id's to retrieve advances.

### `glyphAdvances` [out]

Type: **const INT32***

The returned advances in font design units for
each glyph.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is equivalent to calling [GetGdiCompatibleGlyphMetrics](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getgdicompatibleglyphmetrics) and using only the advance width and height.

Like [GetGdiCompatibleGlyphMetrics](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getgdicompatibleglyphmetrics), these are in
design units, meaning they must be scaled down by
DWRITE_FONT_METRICS::designUnitsPerEm.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)