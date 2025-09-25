# IDWriteTextAnalyzer::GetGlyphs

## Description

 Parses the input text string and maps it to the set of glyphs and associated glyph data
according to the font and the writing system's rendering rules.

## Parameters

### `textString` [in]

Type: **const WCHAR***

An array of characters to convert to glyphs.

### `textLength`

Type: **UINT32**

The length of *textString*.

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

The font face that is the source of the output glyphs.

### `isSideways`

Type: **BOOL**

A Boolean flag set to **TRUE** if the text is intended to be
drawn vertically.

### `isRightToLeft`

Type: **BOOL**

A Boolean flag set to **TRUE** for right-to-left text.

### `scriptAnalysis` [in]

Type: **const [DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)***

A pointer to a Script analysis result from an [AnalyzeScript](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzescript) call.

### `localeName` [in, optional]

Type: **const WCHAR***

The locale to use when selecting glyphs.
For example the same character may map to different glyphs for ja-jp versus zh-chs.
If this is **NULL**, then the default mapping based on the script is used.

### `numberSubstitution` [optional]

Type: **[IDWriteNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritenumbersubstitution)***

A pointer to an optional number substitution which selects the appropriate glyphs for digits and related numeric characters, depending on the results obtained from [AnalyzeNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzenumbersubstitution). Passing **NULL** indicates that no substitution is needed and that the digits should receive nominal glyphs.

### `features` [in, optional]

Type: **const [DWRITE_TYPOGRAPHIC_FEATURES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_typographic_features)****

An array of pointers to the sets of typographic
features to use in each feature range.

### `featureRangeLengths` [in, optional]

Type: **const UINT32***

The length of each feature range, in characters.
The sum of all lengths should be equal to *textLength*.

### `featureRanges`

Type: **UINT32**

The number of feature ranges.

### `maxGlyphCount`

Type: **UINT32**

The maximum number of glyphs that can be
returned.

### `clusterMap` [out]

Type: **UINT16***

When this method returns, contains the mapping from character ranges to glyph
ranges.

### `textProps` [out]

Type: **[DWRITE_SHAPING_TEXT_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_text_properties)***

When this method returns, contains a pointer to an array of structures that contains shaping properties for each character.

### `glyphIndices` [out]

Type: **UINT16***

The output glyph indices.

### `glyphProps` [out]

Type: **[DWRITE_SHAPING_GLYPH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_glyph_properties)***

When this method returns, contains a pointer to an array of structures that contain shaping properties for each output glyph.

### `actualGlyphCount` [out]

Type: **UINT32***

When this method returns, contains the actual number of glyphs returned if
the call succeeds.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note that the mapping from characters to glyphs is, in general, many-to-many. The recommended estimate for the per-glyph output buffers is (3 * *textLength* / 2 + 16). This is not guaranteed to be sufficient.

The value of the *actualGlyphCount* parameter is only valid if the call succeeds. In the event that *maxGlyphCount* is not big enough, **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** will be returned. The application should allocate a larger buffer and try again.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)