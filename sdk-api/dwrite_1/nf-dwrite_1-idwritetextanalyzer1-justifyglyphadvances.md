# IDWriteTextAnalyzer1::JustifyGlyphAdvances

## Description

Justifies an array of glyph advances to fit the line width.

## Parameters

### `lineWidth`

Type: **FLOAT**

The line width.

### `glyphCount`

Type: **UINT32**

The glyph count.

### `justificationOpportunities` [in]

Type: **const [DWRITE_JUSTIFICATION_OPPORTUNITY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_justification_opportunity)***

A pointer to a [DWRITE_JUSTIFICATION_OPPORTUNITY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_justification_opportunity) structure that contains info for the
allowed justification expansion/compression for each glyph. Get this info from [IDWriteTextAnalyzer1::GetJustificationOpportunities](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getjustificationopportunities).

### `glyphAdvances` [in]

Type: **const FLOAT***

An array of glyph advances.

### `glyphOffsets` [in]

Type: **const [DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

An array of glyph offsets.

### `justifiedGlyphAdvances` [out]

Type: **FLOAT***

The returned array of justified glyph advances.

### `justifiedGlyphOffsets` [out, optional]

Type: **[DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

The returned array of justified glyph offsets.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You call **JustifyGlyphAdvances** after you call [IDWriteTextAnalyzer1::GetJustificationOpportunities](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getjustificationopportunities) to collect all the opportunities, and **JustifyGlyphAdvances** spans across the entire line. The input and output arrays are allowed
to alias each other, permitting in-place update.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)

[IDWriteTextAnalyzer1::GetJustificationOpportunities](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getjustificationopportunities)