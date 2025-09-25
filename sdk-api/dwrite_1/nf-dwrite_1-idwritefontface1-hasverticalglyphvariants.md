# IDWriteFontFace1::HasVerticalGlyphVariants

## Description

Determines whether the font has any vertical glyph variants.

## Return value

Returns TRUE if the font contains vertical glyph variants, otherwise FALSE.

## Remarks

For OpenType fonts, **HasVerticalGlyphVariants** returns TRUE if the font contains a "vert"feature.

[IDWriteFontFace1::GetVerticalGlyphVariants](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getverticalglyphvariants) retrieves the vertical forms of the nominal glyphs that are retrieved from [IDWriteFontFace::GetGlyphIndices](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getglyphindices).

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)

[IDWriteFontFace1::GetVerticalGlyphVariants](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getverticalglyphvariants)

[IDWriteFontFace::GetGlyphIndices](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getglyphindices)