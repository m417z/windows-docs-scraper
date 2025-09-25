# Pager_SetButtonSize macro

## Syntax

```cpp
int Pager_SetButtonSize(
   HWND hwnd,
   int  iSize
);
```

## Return value

Type: **int**

Returns an **int** value that contains the previous button size, in pixels.

## Description

Sets the current button size for the pager control. You can use this macro or send the [PGM_SETBUTTONSIZE](https://learn.microsoft.com/windows/desktop/Controls/pgm-setbuttonsize) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `iSize`

Type: **int**

Value of type **int** that contains the new button size, in pixels.

## Remarks

If the pager control has the [PGS_HORZ](https://learn.microsoft.com/windows/desktop/Controls/pager-control-styles) style, the button size determines the width of the pager buttons. If the pager control has the [PGS_VERT](https://learn.microsoft.com/windows/desktop/Controls/pager-control-styles) style, the button size determines the height of the pager buttons. By default, the pager control sets its button size to three-fourths of the width of the scroll bar.

## See also

[Pager_GetButtonSize](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-pager_getbuttonsize)