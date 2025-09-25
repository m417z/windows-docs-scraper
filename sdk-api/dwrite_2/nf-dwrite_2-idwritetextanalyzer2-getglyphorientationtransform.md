# IDWriteTextAnalyzer2::GetGlyphOrientationTransform

## Description

Returns 2x3 transform matrix for the respective angle to draw the
glyph run.

Extends [IDWriteTextAnalyzer1::GetGlyphOrientationTransform](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getglyphorientationtransform) to pass valid values for the baseline origin rather than zeroes.

## Parameters

### `glyphOrientationAngle`

Type: **[DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)**

A [DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)-typed value that specifies the angle that was reported into
[IDWriteTextAnalysisSink1::SetGlyphOrientation](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalysissink1-setglyphorientation).

### `isSideways`

Type: **BOOL**

Whether the run's glyphs are sideways or not.

### `originX`

Type: **FLOAT**

The X value of the baseline origin.

### `originY`

Type: **FLOAT**

The Y value of the baseline origin.

### `transform` [out]

Type: **[DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

Returned transform.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextanalyzer2)