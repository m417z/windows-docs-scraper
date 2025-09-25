# IDWriteFontFace1::GetKerningPairAdjustments

## Description

Retrieves the kerning pair adjustments from the font's kern table.

## Parameters

### `glyphCount`

Type: **UINT32**

Number of glyphs to retrieve adjustments for.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph id's to retrieve adjustments
for.

### `glyphAdvanceAdjustments` [out]

Type: **INT32***

The advances, returned in font design units, for
each glyph. The last glyph adjustment is zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**GetKerningPairAdjustments** isn't a direct replacement for GDI's character based
[GetKerningPairs](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getkerningpairsa), but it serves the same role, without the client
needing to cache them locally. **GetKerningPairAdjustments** also uses glyph id's directly
rather than UCS-2 characters (how the kern table actually stores
them), which avoids glyph collapse and ambiguity, such as the dash
and hyphen, or space and non-breaking space.

Newer fonts may have only GPOS kerning instead of the legacy pair-table kerning. Such fonts, like Gabriola, will only return 0's for
adjustments. **GetKerningPairAdjustments** doesn't virtualize and flatten these
GPOS entries into kerning pairs.

You can realize a performance benefit by calling [IDWriteFontFace1::HasKerningPairs](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-haskerningpairs) to determine whether you need to call **GetKerningPairAdjustments**. If you previously called **IDWriteFontFace1::HasKerningPairs** and it returned FALSE, you can avoid calling **GetKerningPairAdjustments** because the font has no kerning pair-table entries. That is, in this situation, a call to **GetKerningPairAdjustments** would be a no-op.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)

[IDWriteFontFace1::HasKerningPairs](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-haskerningpairs)