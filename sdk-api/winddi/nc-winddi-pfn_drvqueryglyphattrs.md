# PFN_DrvQueryGlyphAttrs callback function

## Description

The **DrvQueryGlyphAttrs** function returns information about a font's glyphs.

## Parameters

### -param

### `unnamedParam1`

#### - iMode [in]

GDI-supplied flag indicating the type of glyph attribute being requested. The following flag is defined:

| Flag | Definition |
| --- | --- |
| FO_ATTR_MODE_ROTATE | The function returns an array indicating which glyphs of a vertical font must be rotated. |

#### - pfo [in]

GDI-supplied pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure identifying the font for which attributes are being requested.

## Return value

**DrvQueryGlyphAttrs** should return a pointer to an [FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr) structure. If an error is encountered, such as an invalid input argument, or if the font described by the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure is not a vertical font, the function should return **NULL**.

## Remarks

The **DrvQueryGlyphAttrs** function should be supplied by font drivers. Currently, the only attribute flag defined is FO_ATTR_MODE_ROTATE, meaning the function should indicate which glyphs of a vertical font must be rotated. (For vertical fonts, DBCS glyphs must be rotated.) This information is useful to printer drivers that support printers having built-in font rasterizers.

The function should return rotation information in the [FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr) structure that is used as the function's return value.

GDI calls the appropriate font driver's **DrvQueryGlyphAttrs** function when a printer driver calls GDI's [FONTOBJ_pQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pqueryglyphattrs) function.

## See also

[FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[FONTOBJ_pQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pqueryglyphattrs)