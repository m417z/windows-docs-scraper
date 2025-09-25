# ListView_GetBkColor macro

## Syntax

```cpp
COLORREF ListView_GetBkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the background color of the list-view control.

## Description

Gets the background color of a list-view control. You can use this macro or send the [LVM_GETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-getbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.