# DrvGetGlyphMode function

## Description

The **DrvGetGlyphMode** function tells GDI how to cache glyph information.

## Parameters

### `unnamedParam1` [in]

Handle to a physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) structure.

### `unnamedParam2` [in]

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that can be queried to find the font size, transform, and other font attributes.

## Return value

**DrvGetGlyphMode** returns one of the following values:

| Return code | Description |
| --- | --- |
| **FO_GLYPHBITS** | GDI should cache all glyph data for this font. |
| **FO_HGLYPHS** | The device caches fonts on its own, so GDI should cache only glyph handles for this font. |
| **FO_PATHOBJ** | GDI should cache PATHOBJ structures for this font. |

## Remarks

GDI calls a driver's **DrvGetGlyphMode** routine to determine the range of font information that should be cached for a particular font; that is, **DrvGetGlyphMode** determines what GDI stores in its font cache. A device that caches fonts on its own should return FO_HGLYPHS to minimize the storage requirements for the font.

GDI calls **DrvGetGlyphMode** for each font realization. For example, a driver might want to download outlines for point sizes larger than 12 point, but raster images for smaller fonts. However, GDI reserves the right to refuse this request.

The driver must check the RASTER_FONTTYPE bit of the **flFontType** member of the FONTOBJ structure to determine the actual form of the glyphs. If this bit is set, GDI is sending bitmaps; otherwise it is sending [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structures.

At the time of the call to **DrvGetGlyphMode**, the associated FONTOBJ is not fully functional. GDI guarantees only that the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure and the notional-to-device transform are correct.

**DrvGetGlyphMode** is an optional driver function. If this function is not provided, GDI will store raster fonts by default.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs)

[GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef)

[GLYPHPOS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphpos)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)