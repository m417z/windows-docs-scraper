## Description

Creates a Color Management dialog box that lets the user choose whether to enable color management and, if so, provides control over the color profiles used and over the [rendering intent](https://learn.microsoft.com/windows/win32/wcs/r).

## Parameters

### `pcms`

Pointer to a [**COLORMATCHSETUPW**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-colormatchsetupw) structure that on entry contains information used to initialize the dialog box.

When **SetupColorMatching** returns, if the user clicked the OK button, this structure contains information about the user's selection. Otherwise, if an error occurred or the user canceled the dialog box, the structure is left unchanged.

## Return value

If this function succeeds, the return value is **TRUE** indicating that no errors occurred and the user clicked the OK button.

If this function fails, the return value is **FALSE** indicating that an error occurred or the dialog was canceled. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)