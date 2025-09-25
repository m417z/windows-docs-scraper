# FONTOBJ_cGetGlyphs function

## Description

The **FONTOBJ_cGetGlyphs** function is a service to the font consumer that translates glyph handles into pointers to glyph data, which are valid until the next call to **FONTOBJ_cGetGlyphs**.

## Parameters

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure containing the glyph handles to be translated.

### `iMode` [in]

Specifies whether data will be written as bitmaps or as outline objects. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| FO_GLYPHBITS | Data will consist of [GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits) structures that define the bitmaps of the glyphs. |
| FO_PATHOBJ | Data will consist of [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structures that define the outlines of the glyphs.<br><br>To determine whether the path should be filled or stroked, the font consumer should check the **flInfo** member of the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure. If the FM_INFO_RETURNS_STROKES flag is set, the path should be stroked; otherwise, the path should be filled. |

### `cGlyph`

Specifies the number of glyphs to be translated. The only acceptable value is 1 (the code assumes 1, regardless of the value specified).

### `phg`

Pointer to an array of *cGlyph* HGLYPH structures supplied by the driver.

### `ppvGlyph`

Pointer to a memory location that receives the address of a [GLYPHDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdata) structure. The first member of this structure is a [GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef) union, which contains a pointer to either a GLYPHBITS structure or a PATHOBJ structure, depending on the value of the *iMode* parameter. If the value of *iMode* is FO_GLYPHBITS, (**ppvGlyph)*->*gdf* contains the address of a GLYPHBITS structure. If the value of *iMode* is FO_PATHOBJ, (**ppvGlyph*)->*gdf* contains the address of a PATHOBJ structure.

## Return value

The return value is the count of pointers passed to the driver if the function is successful. Otherwise, it is zero, and an error code is logged.

## Remarks

This function should be used if the driver is caching fonts.

## See also

[DrvGetGlyphMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetglyphmode)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[FONTOBJ_cGetAllGlyphHandles](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetallglyphhandles)

[GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)