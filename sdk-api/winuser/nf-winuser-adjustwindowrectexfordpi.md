# AdjustWindowRectExForDpi function

## Description

Calculates the required size of the window rectangle, based on the desired size of the client rectangle and the provided DPI. This window rectangle can then be passed to the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create a window with a client area of the desired size.

## Parameters

### `lpRect` [in, out]

A pointer to a **RECT** structure that contains the coordinates of the top-left and bottom-right corners of the desired client area. When the function returns, the structure contains the coordinates of the top-left and bottom-right corners of the window to accommodate the desired client area.

### `dwStyle` [in]

The [Window Style](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) of the window whose required size is to be calculated. Note that you cannot specify the **WS_OVERLAPPED** style.

### `bMenu` [in]

Indicates whether the window has a menu.

### `dwExStyle` [in]

The [Extended Window Style](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles) of the window whose required size is to be calculated.

### `dpi` [in]

The DPI to use for scaling.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns the same result as [AdjustWindowRectEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-adjustwindowrectex) but scales it according to an arbitrary DPI you provide if appropriate.