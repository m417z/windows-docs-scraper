# _UNI_GLYPHSETDATA structure

## Description

The UNI_GLYPHSEDATA structure is one of the structures used to define the contents of [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `dwSize`

Specifies the total size, in bytes, of the .gtt file. Note that this is the total size of all structures used to define the file. This value is not the size of the UNI_GLYPHSETDATA structure.

### `dwVersion`

Specifies the file version number, as defined in prntfont.h by a constant with a name format of UNI_GLYPHSETDATA_VERSION_*x*_*x*.

### `dwFlags`

Not used.

### `lPredefinedID`

Specifies one of the CC_-prefixed code conversion identifiers defined in prntfont.h.

### `dwGlyphCount`

Specifies the number of glyphs provided by this font.

### `dwRunCount`

Specifies the number of [GLYPHRUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_glyphrun) structures in the array pointed to by **loRunOffset**.

### `loRunOffset`

Specifies the byte offset from the beginning of the UNI_GLYPHSETDATA structure to the beginning of an array of [GLYPHRUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_glyphrun) structures.

### `dwCodePageCount`

Specifies the number of [UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo) structures in the array pointed to by **loCodePageOffset**.

### `loCodePageOffset`

Specifies the byte offset from the beginning of the UNI_GLYPHSETDATA structure to the beginning of an array of [UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo) structures.

### `loMapTableOffset`

Specifies the byte offset from the beginning of the UNI_GLYPHSETDATA structure to the beginning of a [MAPTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable) structure.

### `dwReserved`

Reserved for system use.

## Remarks

A UNI_GLYPHSETDATA structure must be the first structure contained in a .gtt file.

## See also

[GLYPHRUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_glyphrun)

[MAPTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable)

[UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo)