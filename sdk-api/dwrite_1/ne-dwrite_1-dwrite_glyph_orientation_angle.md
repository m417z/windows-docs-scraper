# DWRITE_GLYPH_ORIENTATION_ANGLE enumeration

## Description

The **DWRITE_GLYPH_ORIENTATION_ANGLE** enumeration contains values that specify how the glyph is oriented to the x-axis.

## Constants

### `DWRITE_GLYPH_ORIENTATION_ANGLE_0_DEGREES`

Glyph orientation is upright.

### `DWRITE_GLYPH_ORIENTATION_ANGLE_90_DEGREES`

Glyph orientation is rotated 90 degrees clockwise.

### `DWRITE_GLYPH_ORIENTATION_ANGLE_180_DEGREES`

Glyph orientation is upside-down.

### `DWRITE_GLYPH_ORIENTATION_ANGLE_270_DEGREES`

Glyph orientation is rotated 270 degrees clockwise.

## Remarks

The text analyzer outputs **DWRITE_GLYPH_ORIENTATION_ANGLE** values. The value that it outputs depends on the desired orientation, bidi level, and character properties.

## See also

[IDWriteTextAnalysisSink1::SetGlyphOrientation](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalysissink1-setglyphorientation)

[IDWriteTextAnalyzer1::GetGlyphOrientationTransform](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getglyphorientationtransform)