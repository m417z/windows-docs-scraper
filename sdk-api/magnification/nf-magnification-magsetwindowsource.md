# MagSetWindowSource function

## Description

Sets the source rectangle for the magnification window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `rect` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The rectangle to be magnified, in desktop coordinates.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## See also

[MagGetWindowSource](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetwindowsource)