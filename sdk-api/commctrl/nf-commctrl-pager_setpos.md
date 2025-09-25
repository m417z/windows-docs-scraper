# Pager_SetPos macro

## Syntax

```cpp
int Pager_SetPos(
   HWND hwnd,
   int  iPos
);
```

## Return value

Type: **int**

The return value is not used.

## Description

Sets the scroll position for the pager control. You can use this macro or send the [PGM_SETPOS](https://learn.microsoft.com/windows/desktop/Controls/pgm-setpos) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `iPos`

Type: **int**

Value of type **int** that contains the new scroll position, in pixels.