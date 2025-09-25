# GLYPHBITS structure

## Description

The GLYPHBITS structure is used to define a glyph bitmap.

## Members

### `ptlOrigin`

Specifies a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the character in the bitmap.

### `sizlBitmap`

Specifies a SIZEL structure that contains the width and height, in pixels, of the bitmap. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `aj`

Is a variable-sized byte array containing a BYTE-aligned bitmap of the glyph. The array must include padding at the end to DWORD-align the entire structure.

GDI will make this request of drivers that have antialiased fonts (see the description of [DrvQueryFontCaps](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontcaps)). It is possible that a driver may not be able to render a font in a multilevel format. In this case, the driver fails the call and GDI will call the driver again requesting a monochrome realization.

## See also

[DrvGetGlyphMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetglyphmode)

[DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata)

[FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs)

[GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef)