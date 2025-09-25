# IDWriteTextAnalyzer1::GetTextComplexity

## Description

Determines the complexity of text, and whether you need to call [IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) for full script
shaping.

## Parameters

### `textString` [in]

Type: **const WCHAR***

The text to check for complexity. This string
may be UTF-16, but any supplementary characters will be considered
complex.

### `textLength`

Type: **UINT32**

Length of the text to check.

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)***

The font face to read.

### `isTextSimple` [out]

Type: **BOOL***

If true, the text is simple, and the
*glyphIndices* array will already have the nominal glyphs for you.
Otherwise, you need to call [IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) to properly shape complex
scripts and OpenType features.

### `textLengthRead` [out]

Type: **UINT32***

The length read of the text run with the
same complexity, simple or complex. You may call again from that
point onward.

### `glyphIndices` [out, optional]

Type: **UINT16***

Optional glyph indices for the text. If the
function returned that the text was simple, you already have the
glyphs you need. Otherwise the glyph indices are not meaningful,
and you need to call [IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs) for shaping instead.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Text is not simple if the characters are part of a script that has
complex shaping requirements, require bidi analysis, combine with
other characters, reside in the supplementary planes, or have glyphs
that participate in standard OpenType features. The length returned
will not split combining marks from their base characters.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)

[IDWriteTextAnalyzer::GetGlyphs](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-getglyphs)