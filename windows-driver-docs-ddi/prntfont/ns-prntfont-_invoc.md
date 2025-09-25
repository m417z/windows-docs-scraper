# _INVOC structure

## Description

The INVOC structure is used for describing printer command strings in [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files) and [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `dwCount`

Specifies the number of characters in the command.

### `loOffset`

Indicates one of the following:

##### ufm files:

Specifies the byte offset from the beginning of the .ufm file's [UNIDRVINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unidrvinfo) structure to beginning of the command string.

##### gtt files:

Specifies the byte offset from the beginning of the .gtt file's [UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo) structure to beginning of the command string.

## Remarks

INVOC structures are used within [UNIDRVINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unidrvinfo) structures.

## See also

[UNIDRVINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unidrvinfo)