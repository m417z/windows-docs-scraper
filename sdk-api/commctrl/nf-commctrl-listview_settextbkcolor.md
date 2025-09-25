# ListView_SetTextBkColor macro

## Syntax

```cpp
BOOL ListView_SetTextBkColor(
   HWND     hwnd,
   COLORREF clrTextBk
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the background color of text in a list-view control. You can use this macro or send the [LVM_SETTEXTBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-settextbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `clrTextBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new text background color. This can be CLR_NONE for no background color.