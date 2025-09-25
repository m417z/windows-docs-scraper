# Pager_SetBkColor macro

## Syntax

```cpp
COLORREF Pager_SetBkColor(
   HWND     hwnd,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that contains the previous background color.

## Description

Sets the current background color for the pager control. You can use this macro or send the [PGM_SETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/pgm-setbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** value that contains the new background color of the pager control.

## Remarks

By default, the pager control will use the system button face color as the background color. This is the same color that can be retrieved by calling [GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) with COLOR_BTNFACE.