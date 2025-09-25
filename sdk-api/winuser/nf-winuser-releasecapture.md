# ReleaseCapture function

## Description

Releases the mouse capture from a window in the current thread and restores normal mouse input processing. A window that has captured the mouse receives all mouse input, regardless of the position of the cursor, except when a mouse button is clicked while the cursor hot spot is in the window of another thread.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application calls this function after calling the [SetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcapture) function.

#### Examples

For an example, see [Drawing Lines with the Mouse](https://learn.microsoft.com/windows/desktop/inputdev/using-mouse-input).

## See also

**Conceptual**

[GetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcapture)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**

[SetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcapture)

[WM_CAPTURECHANGED](https://learn.microsoft.com/windows/desktop/inputdev/wm-capturechanged)