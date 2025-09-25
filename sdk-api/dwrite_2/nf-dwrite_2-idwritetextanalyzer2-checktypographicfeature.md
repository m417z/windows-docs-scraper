# IDWriteTextAnalyzer2::CheckTypographicFeature

## Description

Checks if a typographic feature is available for a glyph or a set of glyphs.

## Parameters

### `fontFace`

The font face to read glyph information from.

### `scriptAnalysis`

The script analysis for the script or font to check.

### `localeName` [in, optional]

The locale name to check.

### `featureTag`

The font feature tag to check.

### `glyphCount`

The number of glyphs to check.

### `glyphIndices` [in]

An array of glyph indices to check.

### `featureApplies` [out]

An array of integers that indicate whether or not the font feature applies to each glyph specified.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextanalyzer2)