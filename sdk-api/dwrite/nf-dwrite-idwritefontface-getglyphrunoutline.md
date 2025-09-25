# IDWriteFontFace::GetGlyphRunOutline

## Description

 Computes the outline of a run of glyphs by calling back to the outline sink interface.

## Parameters

### `emSize`

Type: **FLOAT**

The logical size of the font in DIP units. A DIP ("device-independent pixel") equals 1/96 inch.

### `glyphIndices` [in]

Type: **const UINT16***

An array of glyph indices. The glyphs are in logical order and the advance direction depends on the *isRightToLeft* parameter. The array must be allocated and be able to contain the number of elements specified by *glyphCount*.

### `glyphAdvances` [in, optional]

Type: **const FLOAT***

An optional array of glyph advances in DIPs. The advance of a glyph is the amount to advance the position (in the direction of the baseline) after drawing the glyph. *glyphAdvances* contains the number of elements specified by *glyphCount*.

### `glyphOffsets` [in, optional]

Type: **const [DWRITE_GLYPH_OFFSET](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_offset)***

An optional array of glyph offsets, each of which specifies the offset along the baseline and offset perpendicular to the baseline of a glyph relative to the current pen position. *glyphOffsets* contains the number of elements specified by *glyphCount*.

### `glyphCount`

Type: **UINT32**

The number of glyphs in the run.

### `isSideways`

Type: **BOOL**

If **TRUE**, the ascender of the glyph runs alongside the baseline. If **FALSE**, the glyph ascender runs perpendicular to the baseline. For example, an English alphabet on a vertical baseline would have *isSideways* set to **FALSE**.

A client can render a vertical run by setting *isSideways* to **TRUE** and rotating the resulting geometry 90 degrees to the
right using a transform. The *isSideways* and *isRightToLeft* parameters cannot both be true.

### `isRightToLeft`

Type: **BOOL**

The visual order of the glyphs. If this parameter is **FALSE**, then glyph advances are from left to right. If **TRUE**, the advance direction is right to left. By default, the advance direction
is left to right.

### `geometrySink`

Type: **[IDWriteGeometrySink](https://learn.microsoft.com/windows/win32/DirectWrite/idwritegeometrysink)***

A pointer to the interface that is called back to perform outline drawing operations.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)