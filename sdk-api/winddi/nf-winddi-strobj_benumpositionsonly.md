# STROBJ_bEnumPositionsOnly function

## Description

The **STROBJ_bEnumPositionsOnly** function enumerates glyph identities and positions for a specified text string, but does not create cached glyph bitmaps.

## Parameters

### `pstro`

A caller-supplied pointer to a [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure describing a text string. This is typically the STROBJ structure received by the driver's [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) function.

### `pc`

A caller-supplied address to receive the GDI-supplied number of GLYPHPOS structures pointed to by the pointer in *ppgpos*.

### `ppgpos`

A caller-supplied address that receives a GDI-supplied pointer to an array of [GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos) structures. (See the following **Remarks** section.)

## Return value

The return value is **TRUE** if more glyphs remain to be enumerated, or **FALSE** if the enumeration is complete. The return value is DDI_ERROR if the glyphs cannot be enumerated, and an error code is logged.

## Remarks

The **STROBJ_bEnumPositionsOnly** function is typically called from within a driver's [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) function. It performs the same operations as [STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum) with one important exception − GDI does not create cached bitmaps of the glyphs. The **STROBJ_bEnum** function assumes the driver will eventually need these bitmaps. However, many newer printers contain internal rasterizers and therefore do not need GDI to render glyphs. For such printers, eliminating the automatic rendering and caching of glyph bitmaps in server memory provides considerable savings of both processing time and memory allocation.

For printers that support internal glyph rasterization, the following rules should be followed:

* The driver should set the GCAPS_FONT_RASTERIZER flag in its [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.
* The driver's *DrvTextOut* function should call **STROBJ_bEnumPositionsOnly** instead of **STROBJ_bEnum**.
* If the print job includes a font that the device cannot rasterize internally, the driver should call [FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs) to obtain glyph bitmaps.
* If a driver needs to determine the likely printer position after a text string has been printed, but does not need a font glyph, it can call [STROBJ_bGetAdvanceWidths](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_bgetadvancewidths).

Because GDI does not create cached bitmaps of the glyphs, the contents of the [GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef) union within each returned [GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos) structure will be **NULL**.

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs)

[GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef)

[GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum)

[STROBJ_bGetAdvanceWidths](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_bgetadvancewidths)