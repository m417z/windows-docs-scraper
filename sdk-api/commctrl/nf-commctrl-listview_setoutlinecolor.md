# ListView_SetOutlineColor macro

## Syntax

```cpp
COLORREF ListView_SetOutlineColor(
   HWND     hwnd,
   COLORREF color
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **COLORREF** structure that contains the outline color.

## Description

Sets the color of the border of a list-view control if the [LVS_EX_BORDERSELECT](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) extended window style is set. You can use this macro or send the [LVM_SETOUTLINECOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-setoutlinecolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `color`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF**

## Remarks

To use **ListView_SetOutlineColor**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).