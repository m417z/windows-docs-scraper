# MagGetWindowSource function

## Description

Gets the rectangle of the area that is being magnified.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pRect` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The rectangle that is being magnified, in desktop coordinates.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## See also

[MagSetWindowSource](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowsource)