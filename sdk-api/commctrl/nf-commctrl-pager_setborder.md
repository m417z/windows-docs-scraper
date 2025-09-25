# Pager_SetBorder macro

## Syntax

```cpp
INT Pager_SetBorder(
   HWND hwnd,
   int  iBorder
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an INT value that contains the previous border size, in pixels.

## Description

Sets the current border size for the pager control. You can use this macro or send the [PGM_SETBORDER](https://learn.microsoft.com/windows/desktop/Controls/pgm-setborder) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `iBorder`

Type: **int**

New size of the border, in pixels. This value should not be larger than the pager button or less than zero. If *iBorder* is too large, the border will be drawn the same size as the button. If
*iBorder* is negative, the border size will be set to zero.