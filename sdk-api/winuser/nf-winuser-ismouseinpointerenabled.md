# IsMouseInPointerEnabled function

## Description

Indicates whether [EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer) is set for the mouse to act as a pointer input device and send [WM_POINTER](https://learn.microsoft.com/windows/win32/inputmsg/messages) messages.

## Return value

If [EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer) is set, the return value is nonzero.

If [EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer) is not set, the return value is zero.

## Remarks

[EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer) can be called only once in the context of a process lifetime. Prior to the first call, Windows Store apps run with mouse-in-pointer enabled, as do any desktop applications that consume mshtml.dll. All other desktop applications run with mouse-in-pointer disabled.

On the first call to [EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer) in the process lifetime, the state is changed as specified and the call succeeds.

On subsequent calls to [EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer), the state will not change. If the current state is not equal to the specified state, the call fails.

Call **IsMouseInPointerEnabled** to verify the mouse-in-pointer state.

## See also

[EnableMouseInPointer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemouseinpointer)

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[WM_POINTER](https://learn.microsoft.com/windows/win32/inputmsg/messages)