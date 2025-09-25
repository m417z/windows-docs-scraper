# IsWindow function

## Description

Determines whether the specified window handle identifies an existing window.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

If the window handle identifies an existing window, the return value is nonzero.

If the window handle does not identify an existing window, the return value is zero.

## Remarks

A thread should not use **IsWindow** for a window that it did not create because the window could be destroyed after this function was called. Further, because window handles are recycled the handle could even point to a different window.

#### Examples

For an example, see [Creating a Modeless Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[IsWindowEnabled](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowenabled)

[IsWindowVisible](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowvisible)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)