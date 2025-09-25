# IsHungAppWindow function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Determines whether the system considers that a specified application is not responding.
An application is considered to be not responding if it is not waiting for input, is not in
startup processing, and has not called [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) within
the internal timeout period of 5 seconds.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

The return value is **TRUE** if the window stops responding; otherwise, it is **FALSE**. Ghost windows always return
**TRUE**.

## Remarks

The Windows timeout criteria of 5 seconds is subject to change.

This function was not included in the SDK headers and libraries until Windows XP Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

**Conceptual**

[IsWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)