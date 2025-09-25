# MMC_TASK_DISPLAY_BITMAP structure

## Description

The
**MMC_TASK_DISPLAY_BITMAP** structure is introduced in MMC 1.1.

The
**MMC_TASK_DISPLAY_BITMAP** structure is used for the **uBitmap** member of the
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure to specify all the data required to display a GIF or bitmap image for a task or background on a taskpad.

## Members

### `szMouseOverBitmap`

A pointer to a null-terminated string that contains the resource path to the image file for the image displayed for the task when the user moves the mouse over the task's image or text area.

The string should have the following form:

"res://*filepath*/*imgpath*"

where *filepath* is the full path to the snap-in's DLL that stores the image file as a resource, and *imgpath* is the resource path of the image file with the snap-in DLL.

For example, the following string specifies that the snap-in DLL (snapin.dll) has a path of "c:\windows\system32\snapin.dll" and that the resource path is img/mon.gif: "res://c:\\windows\\system32\\snapin.dll/img/mon.bmp".

If *szMouseOverBitmap* points to a **NULL** string, *szMouseOffBitmap* must be a valid string that contains the location of a valid image. If one of these strings is **NULL**, the other string is used for both. If both mouse image locations are **NULL**, the task is not displayed.

### `szMouseOffBitmap`

A pointer to a null-terminated string that contains the resource path to the image file for the image displayed for the task when the mouse is not in the task's image or text area.

See **szMouseOverBitmap** for the format of the string.

If **szMouseOffBitmap** points to a **NULL** string, **szMouseOverBitmap** must be a valid string that contains the location of a valid image. If one of these strings is **NULL**, the other string is used for both. If both mouse image locations are **NULL**, the task is not displayed.

## Remarks

Allocate the **szMouseOverBitmap** and **szMouseOffBitmap** strings used in the structure with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release them.

If both **szMouseOverBitmap** and **szMouseOffBitmap** point to a **NULL** string, the task does not appear on the taskpad. If one of these strings is **NULL**, the other string is used for both.

## See also

[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next)

[IExtendTaskPad::GetBackground](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getbackground)

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object)

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol)

[MMC_TASK_DISPLAY_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_task_display_type)