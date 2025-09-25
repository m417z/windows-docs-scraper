# IDWriteFontFace1::GetVerticalGlyphVariants

## Description

Retrieves the vertical forms of the nominal glyphs retrieved from
GetGlyphIndices.

## Parameters

### `glyphCount`

Type: **UINT32**

The number of glyphs to retrieve.

### `nominalGlyphIndices` [in]

Type: **const UINT16***

Original glyph indices from cmap.

### `verticalGlyphIndices` [out]

Type: **UINT16***

The vertical form of glyph indices.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The retrieval uses the font's 'vert' table. This is used in
CJK vertical layout so the correct characters are shown.

Call [GetGlyphIndices](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getglyphindices) to get the nominal glyph indices, followed by
calling this to remap the to the substituted forms, when the run
is sideways, and the font has vertical glyph variants. See [HasVerticalGlyphVariants](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-hasverticalglyphvariants) for more info.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)