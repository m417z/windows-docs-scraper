# IDWriteTextAnalysisSink1::SetGlyphOrientation

## Description

The text analyzer calls back to this to report the actual orientation
of each character for shaping and drawing.

## Parameters

### `textPosition`

Type: **UINT32**

The starting position to report from.

### `textLength`

Type: **UINT32**

Number of UTF-16 units of the reported range.

### `glyphOrientationAngle`

Type: **[DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)**

A [DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)-typed value that specifies the angle of the glyphs within the text
range (pass to [IDWriteTextAnalyzer1::GetGlyphOrientationTransform](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getglyphorientationtransform) to get the world
relative transform).

### `adjustedBidiLevel`

Type: **UINT8**

The adjusted bidi level to be used by
the client layout for reordering runs. This will differ from the
resolved bidi level retrieved from the source for cases such as
Arabic stacked top-to-bottom, where the glyphs are still shaped
as RTL, but the runs are TTB along with any CJK or Latin.

### `isSideways`

Type: **BOOL**

Whether the glyphs are rotated on their side,
which is the default case for CJK and the case stacked Latin

### `isRightToLeft`

Type: **BOOL**

Whether the script should be shaped as
right-to-left. For Arabic stacked top-to-bottom, even when the
adjusted bidi level is coerced to an even level, this will still
be true.

## Return value

Type: **HRESULT**

Returns a successful code or an error code to abort analysis.

## See also

[IDWriteTextAnalysisSink1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalysissink1)