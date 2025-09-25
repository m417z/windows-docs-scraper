# FONTOBJ_pQueryGlyphAttrs function

## Description

The **FONTOBJ_pQueryGlyphAttrs** function returns information about a font's glyphs.

## Parameters

### `pfo`

Is a caller-supplied pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure identifying the font for which attributes are being requested.

### `iMode` [in]

Is a caller-supplied flag indicating the type of glyph attribute being requested. The following flag is defined:

| Flag | Definition |
| --- | --- |
| FO_ATTR_MODE_ROTATE | The function returns an array indicating which glyphs of a vertical font must be rotated. |

## Return value

**FONTOBJ_pQueryGlyphAttrs** returns a pointer to an [FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr) structure. If an error is encountered, such as an invalid input argument, or if the font described by the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure is not a vertical font, the function returns **NULL**.

## Remarks

Currently, the only attribute flag defined is FO_ATTR_MODE_ROTATE. This flag is meant for use by printer drivers that support printers with built-in font rasterizers. The driver can call the **FONTOBJ_pQueryGlyphAttrs** function, specifying the FO_ATTR_MODE_ROTATE flag, to determine which glyphs within a vertical font must be rotated.

Vertical fonts have a font name that starts with the "@" character. To determine if the current font is a vertical font, the driver can check for the FO_VERT_FACE flag in the **flFontType** member of the font's [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure.

Rotation information is returned in the [FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr) structure that is used as the function's return value.

The **FONTOBJ_pQueryGlyphAttrs** function is supplied by GDI. When a printer driver calls **FONTOBJ_pQueryGlyphAttrs**, GDI calls the appropriate font driver's [DrvQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nc-winddi-pfn_drvqueryglyphattrs) function to obtain the requested information.

## See also

[DrvQueryGlyphAttrs](https://learn.microsoft.com/windows/desktop/api/winddi/nc-winddi-pfn_drvqueryglyphattrs)

[FD_GLYPHATTR](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphattr)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)