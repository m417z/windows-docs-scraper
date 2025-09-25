# _MAPTABLE structure

## Description

The MAPTABLE structure is one of the structures used to define the contents of [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `dwSize`

Specifies the size, in bytes, of the MAPTABLE structure, including the **Trans** array.

### `dwGlyphNum`

Specifies the number of elements in the **Trans** array.

### `Trans`

Is an array of [TRANSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_transdata) structures.

## Remarks

A .gtt file's MAPTABLE structure, which contains a glyph mapping table, is accessed by a pointer in the file's [UNI_GLYPHSETDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata) structure. The table maps glyph handles to the character codes or commands that must be sent to the printer in order to print glyphs.

## See also

[TRANSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_transdata)