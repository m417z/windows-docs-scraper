## Description

The TRANSDATA structure is one of the structures used to define the contents of [glyph translation table files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.gtt files).

## Members

### `ubCodePageID`

Specifies the zero-based index of a particular structure in the array of [**UNI_CODEPAGEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo) structures. The first structure in this array has an index of 0, the second structure has an index of 1, and so on.

The **loCodePageOffset** member of the [**UNI_GLYPHSETDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata) structure contains the offset from the beginning of the UNI_GLYPHSETDATA structure to the beginning of the array of UNI_CODEPAGEINFO structures.

### `ubType`

Is a set of one or more bit flags, as follows:

One of the following three format flags can be set:

| Flag | Format |
|---|---|
| MTYPE_COMPOSE | The **sCode** member of the **uCode** union contains an offset to a string. The string contains a command to be sent to the printer. |
| MTYPE_DIRECT | The **ubCode** member of the **uCode** union contains a one-byte character code to be sent to the printer. |
| MTYPE_PAIRED | The **ubPairs** member of the **uCode** union contains a two-byte character code to be sent to the printer. |

One of the action following flags can be set. All are optional. Not valid if the **lPredefinedID** member of the [**UNI_GLYPHSETDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata) structure is set to CC_NOPRECNV.

| Flag | Action |
|---|---|
| MTYPE_ADD | The specified mapping is added to the map table contained in the .gtt file specified by the **lPredefinedID** member of the UNI_GLYPHSETDATA structure. |
| MTYPE_DISABLE | The specified mapping, contained in the .gtt file specified by the **lPredefinedID** member of the [**UNI_GLYPHSETDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata) structure, is disabled. |
| MTYPE_REPLACE | The specified mapping replaces mapping in the map table contained in the .gtt file specified by the **lPredefinedID** member of the UNI_GLYPHSETDATA structure. |

One of the following East Asian flags can be set:

| Flag | East Asian Format |
|---|---|
| MTYPE_SINGLE | Character data is single-byte. |
| MTYPE_DOUBLE | Character data is double-byte. |

### `uCode`

### `uCode.sCode`

Specifies the offset to a command string. The offset is relative to the beginning of the [**MAPTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable) structure containing the TRANSDATA array. The first word of the command string must be the command size. Valid if the MTYPE_COMPOSE flag is set in **uType**.

### `uCode.ubCode`

Specifies a one-byte character code. Valid if the MTYPE_DIRECT flag is set in **uType**.

### `uCode.ubPairs`

Specifies a two-byte character code. Valid if the MTYPE_PAIRED flag is set in **uType**.

## Remarks

A .gtt file's TRANSDATA structure array, which contains glyph mapping information, is contained in the file's [**MAPTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable) structure.

## See also

[**MAPTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable)

[**UNI_CODEPAGEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo)

[**UNI_GLYPHSETDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_glyphsetdata)