# ListView_SetBkColor macro

## Syntax

```cpp
BOOL ListView_SetBkColor(
   HWND     hwnd,
   COLORREF clrBk
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the background color of a list-view control. You can use this macro or send the [LVM_SETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `clrBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The background color to set or the CLR_NONE value for no background color. List-view controls with background colors redraw themselves significantly faster than those without background colors.