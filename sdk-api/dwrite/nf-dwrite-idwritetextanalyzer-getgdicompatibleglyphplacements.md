# IDWriteTextAnalyzer::GetGdiCompatibleGlyphPlacements

## Description

Place glyphs output from the [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) method according to the font
and the writing system's rendering rules.

## Parameters

### `textString` [in]

Type: **const WCHAR***

An array of characters containing the original string from which the glyphs came.

### `clusterMap` [in]

Type: **const UINT16***

A pointer to the mapping from character ranges to glyph
ranges. This is returned by [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `textProps` [in]

Type: **[DWRITE_SHAPING_TEXT_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_text_properties)***

A pointer to an array of structures that contains shaping properties for each character. This structure is returned by
[GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `textLength`

Type: **UINT32**

The text length of *textString*.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph indices returned by [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `glyphProps` [in]

Type: **const [DWRITE_SHAPING_GLYPH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_glyph_properties)***

A pointer to an array of structures that contain shaping properties for each glyph returned by [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `glyphCount`

Type: **UINT32**

The number of glyphs returned from [GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `fontFace` [in]

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

A pointer to the font face that is the source for the output glyphs.

### `fontEmSize`

Type: **FLOAT**

The logical font size in DIPs.

### `pixelsPerDip`

Type: **FLOAT**

The number of physical pixels per DIP.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

An optional transform applied to the glyphs and their positions. This transform is applied after the scaling specified by the font size and *pixelsPerDip*.

### `useGdiNatural`

Type: **BOOL**

When set to **FALSE**, the metrics are the same as the metrics of GDI aliased text. When set to **TRUE**, the metrics are the same as the metrics of text measured by GDI using a font created with **CLEARTYPE_NATURAL_QUALITY**.

### `isSideways`

Type: **BOOL**

A Boolean flag set to **TRUE** if the text is intended to be
drawn vertically.

### `isRightToLeft`

Type: **BOOL**

A Boolean flag set to **TRUE** for right-to-left text.

### `scriptAnalysis` [in]

Type: **const [DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)***

A pointer to a Script analysis result from an[AnalyzeScript](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzescript) call.

### `localeName` [in, optional]

Type: **const WCHAR***

An array of characters containing the locale to use when selecting glyphs.
For example, the same character may map to different glyphs for ja-jp versus zh-chs.
If this is **NULL**, then the default mapping based on the script is used.

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

### `glyphAdvances` [out]

Type: **FLOAT***

When this method returns, contains the advance width of each glyph.

### `glyphOffsets` [out]

Type: **[DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

When this method returns, contains the offset of the origin of each glyph.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)