# CloseWindowStation function

## Description

Closes an open window station handle.

## Parameters

### `hWinSta` [in]

A handle to the window station to be closed. This handle is returned by the
[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa) or
[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa) function. Do not specify the handle returned by the [GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Windows Server 2003 and Windows XP/2000:** This function does not set the last error code on failure.

## Remarks

The
**CloseWindowStation** function will fail if the handle being closed is for the window station assigned to the calling process.

## See also

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)