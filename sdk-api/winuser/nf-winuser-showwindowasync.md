# ShowWindowAsync function

## Description

Sets the show state of a window without waiting for the operation to complete.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `nCmdShow` [in]

Type: **int**

Controls how the window is to be shown. For a list of possible values, see the description of the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

## Return value

Type: **BOOL**

If the operation was successfully started, the return value is nonzero.

## Remarks

This function posts a show-window event to the message queue of the given window. An application can use this function to avoid becoming nonresponsive while waiting for a nonresponsive application to finish processing a show-window event.

## See also

**Conceptual**

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)