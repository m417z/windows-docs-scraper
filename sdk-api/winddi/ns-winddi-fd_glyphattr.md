# FD_GLYPHATTR structure

## Description

The FD_GLYPHATTR structure is used to specify the return value for the [FONTOBJ_pQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pqueryglyphattrs) and [DrvQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nc-winddi-pfn_drvqueryglyphattrs) functions.

## Members

### `cjThis`

Is the size in bytes of the FD_GLYPHATTR structure, including the array specified by the **aGlyphAttr** member.

### `cGlyphs`

Specifies the number of glyphs in the font.

### `iMode`

Is a flag indicating the type of information being returned. The following flag is defined:

| Flag | Definition |
| --- | --- |
| FO_ATTR_MODE_ROTATE | The array specified by **aGlyphAttr** is a bit array indicating which glyphs of a vertical font must be rotated. The bit array's length is (**cGlyphs**+7)/8. If a glyph's bit is set, the glyph should be rotated during rasterization. |

### `aGlyphAttr`

Is an array supplying the information specified by **iMode**. The size of this array is (**cGlyphs**+7) / 8 bytes.

## Remarks

If **iMode** is FO_ATTR_MODE_ROTATE (the only flag currently defined), a printer driver can determine the bit that corresponds to a particular glyph index using the following code fragment, where *hg* is the glyph index and *pga* is a pointer to an FD_GLYPHATTR structure. If the bit in the **aGlyphAttr** array associated with glyph index *hg* is set, *result* is set to 1. If the same bit in the array is not set, *result* is set to 0. Note that the bits within a byte are stored so that glyph indexes 0, 1, ..., 7 correspond to bit positions 7, 6, ..., 0 within **aGlyphAttr**[0], glyph indexes 8, 9, ..., 15 correspond to bit positions 7, 6, ..., 0 within **aGlyphAttr**[1], and so on.

```
BYTE glyphBits[8] = {0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
result = (pga->aGlyphAttr[hg / 8]) & (glyphBits[hg % 8]);
```