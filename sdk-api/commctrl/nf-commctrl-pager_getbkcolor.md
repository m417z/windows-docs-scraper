# Pager_GetBkColor macro

## Syntax

```cpp
COLORREF Pager_GetBkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the current background color.

## Description

Retrieves the current background color for the pager control. You can use this macro or send the [PGM_GETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/pgm-getbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

## Remarks

By default, the pager control will use the system button face color as the background color. This is the same color that can be retrieved by calling [GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) with COLOR_BTNFACE.