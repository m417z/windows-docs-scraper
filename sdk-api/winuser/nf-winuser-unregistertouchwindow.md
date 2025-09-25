# UnregisterTouchWindow function

## Description

Registers a window as no longer being touch-capable.

## Parameters

### `hwnd` [in]

The handle of the window. The function fails with **ERROR_ACCESS_DENIED** if the calling thread does not own the specified window.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **UnregisterTouchWindow** function succeeds even if the specified window was not previously registered as being touch-capable.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtfunctions)

[RegisterTouchWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registertouchwindow)