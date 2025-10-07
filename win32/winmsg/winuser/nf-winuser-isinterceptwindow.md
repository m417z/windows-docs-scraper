# IsInterceptWindow function

Determines if a window is an Intercept window.

## Parameters

`topLevelWindow`

Type: **HWND**

Handle to the top-level window.

`[out] isIntercept`

Type: **BOOL**

True if the window is an Intercept window; otherwise, false.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero, and the `isIntercept`
out parameter is set to true if the window is an Intercept window.

If the function fails, the return value is zero. To get extended error
information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!TIP]
> At this time, this function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`User32.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

An Intercept windows is a window that had
[**ConvertToInterceptWindow**](https://learn.microsoft.com/windows/win32/winmsg/winuser/nf-winuser-converttointerceptwindow)
called on it. For these windows, windowing operations (moves, sizes, activate,
etc) are intercepted (skipped). This happens for operations that are generated
by the app (like a call to
[**SetWindowPos**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowpos)
) or operations that originate from other apps or the system.

Intercept windows respond to all windowing events asynchronously, for example
because the events are being sent to another machine (Remote Apps).
IsInterceptWindow allows apps to apply special handling for Intercept windows.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | User32.dll |