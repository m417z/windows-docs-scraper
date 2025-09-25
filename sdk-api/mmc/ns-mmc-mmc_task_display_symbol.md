# MMC_TASK_DISPLAY_SYMBOL structure

## Description

The
**MMC_TASK_DISPLAY_SYMBOL** structure is introduced in MMC 1.1.

The
**MMC_TASK_DISPLAY_SYMBOL** structure is used for the **uSymbol** member of the
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure to specify all the data required to display a symbol as an image for a task or background on a taskpad.

## Members

### `szFontFamilyName`

A pointer to a null-terminated string that contains the font family name of the symbol to display.

For example, the following string specifies that the font is Webdings: "Webdings".

This should never be set to a **NULL** string or an empty string.

### `szURLtoEOT`

A pointer to a null-terminated string that contains the resource path to the EOT (embedded OpenType) file that contains the font for the symbol to display.

The string should have the following form: "res://*filepath*/imgpath".

where *filepath* is the full path to the snap-in's DLL that stores the image file as a resource, and *imgpath* is the resource path of the image file with the snap-in DLL.

For example, the following string specifies that the snap-in DLL (snapin.dll) has a path of "c:\windows\system32\snapin.dll" and that the resource path is img/myfont.eot: "res://c:\\windows\\system32\\snapin.dll/img/myfont.eot".

### `szSymbolString`

A pointer to a null-terminated string that contains the character or characters to display in the symbol.

## Remarks

Allocate the *szFontFamilyName*, *szURLtoEOT*, and *szSymbolString* strings used in the structure with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release them.

## See also

[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next)

[IExtendTaskPad::GetBackground](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getbackground)

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap)

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object)

[MMC_TASK_DISPLAY_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_task_display_type)