# Pager_GetPos macro

## Syntax

```cpp
int Pager_GetPos(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns an **int** value that contains the current scroll position, in pixels.

## Description

Retrieves the current scroll position of the pager control. You can use this macro or send the [PGM_GETPOS](https://learn.microsoft.com/windows/desktop/Controls/pgm-getpos) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.