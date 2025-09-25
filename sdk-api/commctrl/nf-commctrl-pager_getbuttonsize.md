# Pager_GetButtonSize macro

## Syntax

```cpp
int Pager_GetButtonSize(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns an **int** value that contains the current button size, in pixels.

## Description

Retrieves the current button size for the pager control. You can use this macro or send the [PGM_GETBUTTONSIZE](https://learn.microsoft.com/windows/desktop/Controls/pgm-getbuttonsize) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

## See also

[Pager_SetButtonSize](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-pager_setbuttonsize)