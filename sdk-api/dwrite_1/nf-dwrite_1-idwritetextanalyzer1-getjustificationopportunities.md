# IDWriteTextAnalyzer1::GetJustificationOpportunities

## Description

Retrieves justification opportunity information for each of the glyphs
given the text and shaping glyph properties.

## Parameters

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)***

Font face that was used for shaping. This is
mainly important for returning correct results of the kashida
width.

May be NULL.

### `fontEmSize`

Type: **FLOAT**

Font em size used for the glyph run.

### `scriptAnalysis`

Type: **[DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)**

Script of the text from the itemizer.

### `textLength`

Type: **UINT32**

Length of the text.

### `glyphCount`

Type: **UINT32**

Number of glyphs.

### `textString` [in]

Type: **const WCHAR***

Characters used to produce the glyphs.

### `clusterMap` [in]

Type: **const UINT16***

Clustermap produced from shaping.

### `glyphProperties` [in]

Type: **const [DWRITE_SHAPING_GLYPH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_glyph_properties)***

Glyph properties produced from shaping.

### `justificationOpportunities` [out]

Type: **[DWRITE_JUSTIFICATION_OPPORTUNITY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_justification_opportunity)***

A pointer to a [DWRITE_JUSTIFICATION_OPPORTUNITY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_justification_opportunity) structure that receives info for the
allowed justification expansion/compression for each glyph.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is called per-run, after shaping is done via the [IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) method.

**Note** this function only supports natural metrics ([DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)).

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)