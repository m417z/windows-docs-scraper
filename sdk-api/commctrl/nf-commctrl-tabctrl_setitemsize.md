# TabCtrl_SetItemSize macro

## Syntax

```cpp
DWORD TabCtrl_SetItemSize(
   HWND hwnd,
   int  x,
   int  y
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the old width and height. The width is in the **LOWORD** of the return value, and the height is in the **HIWORD**.

## Description

Sets the width and height of tabs in a fixed-width or owner-drawn tab control. You can use this macro or send the [TCM_SETITEMSIZE](https://learn.microsoft.com/windows/desktop/Controls/tcm-setitemsize) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `x`

Type: **int**

New width, in pixels.

### `y`

Type: **int**

New height, in pixels.