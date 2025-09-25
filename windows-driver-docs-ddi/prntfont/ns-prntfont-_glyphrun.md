# _GLYPHRUN structure

## Description

The GLYPHRUN structure is one of the structures used to define the contents of [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `wcLow`

Specifies a Unicode value representing the first glyph in the glyph run.

### `wGlyphCount`

Specifies the number of glyphs represented by the glyph run.

## Remarks

A .gtt (glyph translation table) file contains an array of GLYPHRUN structures. Each structure identifies a set of Unicode values for which the printer provides glyphs. The array is described by the **IoRunOffset** and **dwRunCount** members of a .gtt file's [UNI_GLYPHSETDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata) structure.

The GLYPHRUN structures must be defined in ascending order, based on the value of **wcLow**. Unidrv uses the GLYPHRUN array to generate glyph handles. Unidrv stores these glyph handles in a [WCRUN](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-wcrun) array within an [FD_GLYPHSET](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fd_glyphset) structure.

## See also

[FD_GLYPHSET](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fd_glyphset)

[UNI_GLYPHSETDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata)

[WCRUN](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-wcrun)