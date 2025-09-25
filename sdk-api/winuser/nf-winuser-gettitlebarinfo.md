# GetTitleBarInfo function

## Description

Retrieves information about the specified title bar.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the title bar whose information is to be retrieved.

### `pti` [in, out]

Type: **PTITLEBARINFO**

A pointer to a [TITLEBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-titlebarinfo) structure to receive the information. Note that you must set the **cbSize** member to `sizeof(TITLEBARINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

**Reference**

[TITLEBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-titlebarinfo)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)