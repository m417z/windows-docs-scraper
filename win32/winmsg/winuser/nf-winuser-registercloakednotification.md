# RegisterCloakedNotification function

Registers a window for cloak state change notifications.

## Parameters

`[in] hwnd`

Type: **HWND**

Handle to the window whose registration is changing.

`[in] register`

Type: **BOOL**

Indicates if the call is registering the window for cloak state change
notifications.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a window is registered for cloak change notifications the
[WM_CLOAKED_STATE_CHANGED](https://learn.microsoft.com/windows/win32/winmsg/winuser/ns-winuser-wmcloakedstatechanged)
message will be sent to its window procedure when the window's cloak state
changes. A window that is registered for cloak change notifications will receive
the RegisterCloakedNotification can only be called from the thread that owns the
window being registered or unregistered for notifications.

> [!TIP]
> At this time, this function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`User32.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | User32.dll |

## See also

[WM_CLOAKED_STATE_CHANGED](https://learn.microsoft.com/windows/win32/winmsg/winuser/ns-winuser-wmcloakedstatechanged)

[DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute)