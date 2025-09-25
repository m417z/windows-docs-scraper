# GetWindowInfo function

## Description

Retrieves information about the specified window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose information is to be retrieved.

### `pwi` [in, out]

Type: **PWINDOWINFO**

A pointer to a [WINDOWINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowinfo) structure to receive the information. Note that you must set the **cbSize** member to `sizeof(WINDOWINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

**Reference**

[WINDOWINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowinfo)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)