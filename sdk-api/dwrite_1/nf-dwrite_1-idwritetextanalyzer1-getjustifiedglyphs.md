# IDWriteTextAnalyzer1::GetJustifiedGlyphs

## Description

Fills in new glyphs for complex scripts where justification increased
the advances of glyphs, such as Arabic with kashida.

## Parameters

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)***

Font face used for shaping.

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

### `maxGlyphCount`

Type: **UINT32**

Maximum number of output glyphs allocated
by caller.

### `clusterMap` [in, optional]

Type: **const UINT16***

Clustermap produced from shaping.

### `glyphIndices` [in]

Type: **const UINT16***

Original glyphs produced from shaping.

### `glyphAdvances` [in]

Type: **const FLOAT***

Original glyph advances produced from shaping.

### `justifiedGlyphAdvances` [in]

Type: **const FLOAT***

Justified glyph advances from
[IDWriteTextAnalyzer1::JustifyGlyphAdvances](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-justifyglyphadvances).

### `justifiedGlyphOffsets` [in]

Type: **const [DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

Justified glyph offsets from
[IDWriteTextAnalyzer1::JustifyGlyphAdvances](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-justifyglyphadvances).

### `glyphProperties` [in]

Type: **const [DWRITE_SHAPING_GLYPH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_shaping_glyph_properties)***

Properties of each glyph, from [IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs).

### `actualGlyphCount` [out]

Type: **UINT32***

The new glyph count written to the
modified arrays, or the needed glyph count if the size is not
large enough.

### `modifiedClusterMap` [out, optional]

Type: **UINT16***

Updated clustermap.

### `modifiedGlyphIndices` [out]

Type: **UINT16***

Updated glyphs with new glyphs
inserted where needed.

### `modifiedGlyphAdvances` [out]

Type: **FLOAT***

Updated glyph advances.

### `modifiedGlyphOffsets` [out]

Type: **[DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

Updated glyph offsets.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You call **GetJustifiedGlyphs** after the line has been justified, and it is per-run.

You should call **GetJustifiedGlyphs** if [IDWriteTextAnalyzer1::GetScriptProperties](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getscriptproperties) returns a non-null [DWRITE_SCRIPT_PROPERTIES.justificationCharacter](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_script_properties) for that script.

 Use **GetJustifiedGlyphs** mainly for cursive scripts
like Arabic. If *maxGlyphCount* is not large enough, **GetJustifiedGlyphs** returns the error
E_NOT_SUFFICIENT_BUFFER and fills the variable to which *actualGlyphCount* points with
the needed glyph count.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)

[IDWriteTextAnalyzer1::GetScriptProperties](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getscriptproperties)

[IDWriteTextAnalyzer1::JustifyGlyphAdvances](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-justifyglyphadvances)

[IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs)