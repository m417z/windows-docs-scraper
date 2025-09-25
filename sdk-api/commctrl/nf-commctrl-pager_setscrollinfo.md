# Pager_SetScrollInfo macro

## Syntax

```cpp
int Pager_SetScrollInfo(
   HWND hwnd,
   UINT cTimeOut,
   UINT cLinesPer,
   UINT cPixelsPerLine
);
```

## Return value

Type: **int**

The return value is not used.

## Description

[Intended for internal use; not recommended for use in applications. This macro may not be supported in future versions of Windows.]

Sets the scrolling parameters of the pager control, including the timeout value, the lines per timeout, and the pixels per line. You can use this macro or send the [PGM_SETSETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/pgm-setscrollinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `cTimeOut`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The timeout value for the scroll, in milliseconds.

### `cLinesPer`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of lines to scroll per timeout.

### `cPixelsPerLine`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of pixels per line.

## Remarks

This *cTimeOut* parameter controls the rate at which the pager control generates scrolling events when the control has captured the mouse input and the left mouse button is pressed. Smaller values result in faster scrolling; larger values result in slower scrolling. The default value is one-eighth of the double-click time. For more information, see [GetDoubleClickTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdoubleclicktime).

By default, with each scrolling event the pager control scrolls an amount equal to the entire width or height of the control, depending on whether the pager control has a horizontal or vertical orientation. The *cLinesPer* and *cPixelsPerLine* parameters are used to override the default scrolling amount. If nonzero values are provided, the scrolling amount is the product of the two values (*cLinesPer* * *cPixelsPerLine*).

## See also

[PGM_SETSETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/pgm-setscrollinfo)