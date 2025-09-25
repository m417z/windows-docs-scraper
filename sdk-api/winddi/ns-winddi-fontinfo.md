# FONTINFO structure

## Description

The FONTINFO structure contains information regarding a specific font.

## Members

### `cjThis`

Specifies the size of this FONTINFO structure in bytes.

### `flCaps`

Is a set of capabilities flags. The allowed flags are FO_DEVICE_FONT and FO_OUTLINE_CAPABLE.

### `cGlyphsSupported`

Specifies the number of glyphs in the font.

### `cjMaxGlyph1`

Specifies the size of the largest glyph in 1 bit/pixel. A nonzero value implies that 1-bit-per-pixel bitmaps are supported.

### `cjMaxGlyph4`

Specifies the size of the largest glyph in 4 bits/pixel. A nonzero value implies that 4-bit-per-pixel bitmaps are supported.

### `cjMaxGlyph8`

Specifies the size of the largest glyph in 8 bits/pixel. A nonzero value implies that 8-bit-per-pixel bitmaps are supported.

### `cjMaxGlyph32`

Specifies the size of the largest glyph in 32 bits/pixel. A nonzero value implies that 32-bit-per-pixel bitmaps are supported.

## Remarks

GDI writes and returns this structure through [FONTOBJ_vGetInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_vgetinfo).

## See also

[FONTOBJ_vGetInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_vgetinfo)