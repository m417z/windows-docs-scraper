# DWRITE_GLYPH_RUN_DESCRIPTION structure

## Description

Contains additional properties related to those in [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run).

## Members

### `localeName`

Type: **const WCHAR***

An array of characters containing the locale name associated with this run.

### `string`

Type: **const WCHAR***

An array of characters containing the text associated with the glyphs.

### `stringLength`

Type: **UINT32**

The number of characters in UTF16 code-units. Note that this may be different than the number of glyphs.

### `clusterMap`

Type: **const UINT16***

An array of indices to the glyph indices array, of the first glyphs of all the glyph clusters of the glyphs to render.

### `textPosition`

Type: **UINT32**

Corresponding text position in the string this glyph run came from. This is relative to the beginning of the string represented by the [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) object.