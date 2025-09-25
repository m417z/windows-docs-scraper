# IDWriteTextAnalyzer1::ApplyCharacterSpacing

## Description

Applies spacing between characters, properly adjusting glyph clusters
and diacritics.

## Parameters

### `leadingSpacing`

The spacing before each character, in reading order.

### `trailingSpacing`

The spacing after each character, in reading order.

### `minimumAdvanceWidth`

The minimum advance of each character,
to prevent characters from becoming too thin or zero-width. This
must be zero or greater.

### `textLength`

The length of the clustermap and original text.

### `glyphCount`

The number of glyphs.

### `clusterMap` [in]

Mapping from character ranges to glyph ranges.

### `glyphAdvances` [in]

The advance width of each glyph.

### `glyphOffsets` [in]

The offset of the origin of each glyph.

### `glyphProperties` [in]

Properties of each glyph, from GetGlyphs.

### `modifiedGlyphAdvances` [out]

The new advance width of each glyph.

### `modifiedGlyphOffsets` [out]

The new offset of the origin of each glyph.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The input and output advances/offsets are allowed to alias the same array.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)