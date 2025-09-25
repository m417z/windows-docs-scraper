# MagSetWindowFilterList function

## Description

Sets the list of windows to be magnified or the
list of windows to be excluded from magnification.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the magnification window.

### `dwFilterMode` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification filter mode. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| MW_FILTERMODE_INCLUDE | Magnify the windows.<br><br>**Note:** This value is not supported on Windows 7 or newer. |
| MW_FILTERMODE_EXCLUDE | Exclude the windows from magnification. |

### `count` [in]

Type: **int**

The number of window handles in the list.

### `pHWND` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The list of window handles.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

This function requires Windows Display Driver Model (WDDM)-capable video cards.

Only one window list is used. You can specify either MW_FILTERMODE_INCLUDE or MW_FILTERMODE_EXCLUDE,
depending on whether it is more convenient to list included windows or excluded windows.

The magnification window itself is automatically excluded.

## See also

[MagGetWindowFilterList](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetwindowfilterlist)