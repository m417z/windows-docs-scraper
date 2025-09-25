# IDWriteTextAnalysisSource1::GetVerticalGlyphOrientation

## Description

Used by the text analyzer to obtain the desired glyph
orientation and resolved bidi level.

## Parameters

### `textPosition`

Type: **UINT32**

The text position.

### `textLength` [out]

Type: **UINT32***

A pointer to the text length.

### `glyphOrientation` [out]

Type: **[DWRITE_VERTICAL_GLYPH_ORIENTATION](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_vertical_glyph_orientation)***

A [DWRITE_VERTICAL_GLYPH_ORIENTATION](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_vertical_glyph_orientation)-typed value that specifies the desired kind of glyph orientation for the text.

### `bidiLevel` [out]

Type: **UINT8***

A pointer to the resolved bidi level.

## Return value

Type: **HRESULT**

Returning an error will abort the
analysis.

## Remarks

The text analyzer calls back to this to get the desired glyph
orientation and resolved bidi level, which it uses along with the
script properties of the text to determine the actual orientation of
each character, which it reports back to the client via the sink
SetGlyphOrientation method.

## See also

[IDWriteTextAnalysisSource1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalysissource1)