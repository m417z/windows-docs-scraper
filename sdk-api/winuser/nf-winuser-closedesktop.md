# CloseDesktop function

## Description

Closes an open handle to a desktop object.

## Parameters

### `hDesktop` [in]

A handle to the desktop to be closed. This can be a handle returned by the
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa),
[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa), or
[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop) functions. Do not specify the handle returned by the [GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**CloseDesktop** function will fail if any thread in the calling process is using the specified desktop handle or if the handle refers to the initial desktop of the calling process.

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)