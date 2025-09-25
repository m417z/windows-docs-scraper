# ListView_GetTextColor macro

## Syntax

```cpp
COLORREF ListView_GetTextColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the text color.

## Description

Gets the text color of a list-view control. You can use this macro or send the [LVM_GETTEXTCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-gettextcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.