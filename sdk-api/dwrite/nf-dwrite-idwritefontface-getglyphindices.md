# IDWriteFontFace::GetGlyphIndices

## Description

 Returns the nominal mapping of UCS4 Unicode code points to glyph indices as defined by the font 'CMAP' table.

## Parameters

### `codePoints` [in]

Type: **const UINT32***

An array of USC4 code points from which to obtain nominal glyph indices. The array must be allocated and be able to contain the number of elements specified by *codePointCount*.

### `codePointCount`

Type: **UINT32**

The number of elements in the *codePoints* array.

### `glyphIndices` [out]

Type: **UINT16***

When this method returns, contains a pointer to an array of nominal glyph indices filled by this function.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note that this mapping is primarily provided for line layout engines built on top of the physical font API.
Because of OpenType glyph substitution and line layout character substitution, the nominal conversion does not always correspond
to how a Unicode string will map to glyph indices when rendering using a particular font face.
Also, note that Unicode variant selectors provide for alternate mappings for character to glyph.
This call will always return the default variant.

 When characters are not present in the font this method returns the index 0, which is the undefined glyph or ".notdef" glyph. If a character isn't in a font, IDWriteFont::HasCharacter returns false and GetUnicodeRanges doesn't return it in the range.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)