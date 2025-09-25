# STROBJ_bEnum function

## Description

The **STROBJ_bEnum** function enumerates glyph identities and positions.

## Parameters

### `pstro`

Pointer to the [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure containing the [GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos) information.

### `pc`

Pointer to the count, returned by GDI, of GLYPHPOS structures.

### `ppgpos`

Pointer to the array in which GDI writes the GLYPHPOS structures.

## Return value

The return value is **TRUE** if more glyphs remain to be enumerated, or **FALSE** if the enumeration is complete. The return value is DDI_ERROR if the glyphs cannot be enumerated, and an error code is logged.

## Remarks

A driver should download only the glyph handles if it caches fonts itself.

The information returned depends on the driver's return value for [DrvGetGlyphMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetglyphmode).

Bitmaps or outlines can also be obtained from [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structures.

Printer drivers should call [STROBJ_bEnumPositionsOnly](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benumpositionsonly) instead of **STROBJ_bEnum** if printer hardware provides internal rendering of TrueType fonts.

## See also

[DrvGetGlyphMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetglyphmode)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs)

[GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_bEnumPositionsOnly](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benumpositionsonly)

[STROBJ_vEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_venumstart)