# Pager_GetBorder macro

## Syntax

```cpp
int Pager_GetBorder(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns an **int** value that contains the current border size, in pixels.

## Description

Retrieves the current border size for the pager control. You can use this macro or send the [PGM_GETBORDER](https://learn.microsoft.com/windows/desktop/Controls/pgm-getborder) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.