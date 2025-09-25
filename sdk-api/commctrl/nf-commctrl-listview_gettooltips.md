# ListView_GetToolTips macro

## Syntax

```cpp
HWND ListView_GetToolTips(
   HWND hwndLV
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the tooltip control.

## Description

Gets the tooltip control that the list-view control uses to display tooltips. You can use this macro or send the [LVM_GETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-gettooltips) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## See also

[ListView_SetToolTips](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_settooltips)