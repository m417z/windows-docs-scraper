# SwitchToThisWindow function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Switches
focus to the specified window and brings it to the foreground.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window.

### `fUnknown` [in]

Type: **BOOL**

A **TRUE** for this parameter indicates that the window
is being switched to using the Alt/Ctl+Tab key sequence. This parameter
should be **FALSE** otherwise.

## Remarks

This function is typically called to maintain window z-ordering.

This function was not included in the SDK headers and libraries until Windows XP with Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

**Conceptual**

[IsWindowVisible](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowvisible)

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)