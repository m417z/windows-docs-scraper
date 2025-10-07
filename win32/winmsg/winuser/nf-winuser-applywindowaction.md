# ApplyWindowAction function

Applies changes described in a
[WINDOW_ACTION](https://learn.microsoft.com/windows/win32/winmsg/winuser/ns-winuser-windowaction)
to a top level window.

## Parameters

`hwnd`

Type: **HWND**

Handle to the top-level window.

`pAction`

Type: **WINDOW_ACTION**

The window action to apply.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error
information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Limited Access Feature (LAF) approval

> [!IMPORTANT]
> The API ApplyWindowAction is a Limited Access Feature (see
[LimitedAccessFeatures class](https://learn.microsoft.com/uwp/api/windows.applicationmodel.limitedaccessfeatures))
. For more information or to request an unlock token, please use the
[LAF Access Token Request Form](https://go.microsoft.com/fwlink/?linkid=2271232&clcid=0x409)
and select 'Remote App Windowing APIs' from the drop down.

## Remarks

> [!TIP]
> At this time, this function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`User32.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

The
[WINDOW_ACTION](https://learn.microsoft.com/windows/win32/winmsg/winuser/ns-winuser-windowaction)
describes one or more changes to a top level window's position, size, state,
and other related fields. `ApplyWindowAction` applies the changes to the provided
window, moving, sizing, etc, depending on the values set in the action.

## Requirements

The provided window must be a top level window owned by the calling thread.

The window and the calling thread must be Per-Monitor DPI Aware.

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | User32.dll |