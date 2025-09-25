# ListView_GetTextBkColor macro

## Syntax

```cpp
COLORREF ListView_GetTextBkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the background color of the text.

## Description

Gets the text background color of a list-view control. You can use this macro or send the [LVM_GETTEXTBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-gettextbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.