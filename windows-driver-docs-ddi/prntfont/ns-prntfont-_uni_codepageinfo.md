# _UNI_CODEPAGEINFO structure

## Description

The UNI_CODEPAGEINFO structure is one of the structures used to define the contents of [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `dwCodePage`

Identifies a Windows code page.

### `SelectSymbolSet`

Is an [INVOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_invoc) structure containing the printer command to select the code page's symbol set.

### `UnSelectSymbolSet`

Is an [INVOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_invoc) structure containing the printer command to deselect the code page's symbol set.

## See also

[INVOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_invoc)