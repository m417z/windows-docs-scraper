# IDWriteFontFace1::GetDesignGlyphAdvances

## Description

Retrieves the advances in design units for a sequences of glyphs.

## Parameters

### `glyphCount`

Type: **UINT32**

The number of glyphs to retrieve advances for.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph id's to retrieve advances for.

### `glyphAdvances` [out]

Type: **INT32***

The returned advances in font design units for
each glyph.

### `isSideways`

Type: **BOOL**

Retrieve the glyph's vertical advance height
rather than horizontal advance widths.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is equivalent to calling GetGlyphMetrics and using only the
advance width and height.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)