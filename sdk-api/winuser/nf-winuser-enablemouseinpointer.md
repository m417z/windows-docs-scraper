# EnableMouseInPointer function

## Description

Enables the mouse to act as a pointer input device and send [WM_POINTER](https://learn.microsoft.com/windows/win32/inputmsg/messages) messages.

## Parameters

### `fEnable` [in]

**TRUE** to turn on mouse input support in [WM_POINTER](https://learn.microsoft.com/windows/win32/inputmsg/messages).

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can be called only once in the context of a process lifetime. Prior to the first call, Windows Store apps run with mouse-in-pointer enabled, as do any desktop applications that consume mshtml.dll. All other desktop applications run with mouse-in-pointer disabled.

On the first call in the process lifetime, the state is changed as specified and the call succeeds.

On subsequent calls, the state will not change. If the current state is not equal to the specified state, the call fails.

Call [IsMouseInPointerEnabled](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ismouseinpointerenabled) to verify the mouse-in-pointer state.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)

[IsMouseInPointerEnabled](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ismouseinpointerenabled)

[WM_POINTER](https://learn.microsoft.com/windows/win32/inputmsg/messages)