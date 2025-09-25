# ListView_SetToolTips macro

## Syntax

```cpp
HWND ListView_SetToolTips(
   HWND hwndLV,
   HWND hwndNewHwnd
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the previous tooltip control.

## Description

Sets the tooltip control that the list-view control will use to display tooltips. You can use this macro or send the [LVM_SETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-settooltips) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `hwndNewHwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the tooltip control to be set.

## See also

[ListView_GetToolTips](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_gettooltips)