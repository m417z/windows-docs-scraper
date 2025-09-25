# DeregisterShellHookWindow function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Unregisters a specified Shell window that is registered to receive Shell
hook messages.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window to be unregistered. The window was registered with a call to the
[RegisterShellHookWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registershellhookwindow) function.

## Return value

Type: **BOOL**

**TRUE** if the function succeeds; **FALSE** if the
function fails.

## Remarks

This function was not included in the SDK headers and libraries until Windows XP with Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

**Conceptual**

**Reference**

[RegisterShellHookWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registershellhookwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)