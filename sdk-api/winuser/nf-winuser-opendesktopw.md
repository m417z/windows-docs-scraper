# OpenDesktopW function

## Description

Opens the specified desktop object.

## Parameters

### `lpszDesktop` [in]

The name of the desktop to be opened. Desktop names are case-insensitive.

This desktop must belong to the current window station.

### `dwFlags` [in]

This parameter can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **DF_ALLOWOTHERACCOUNTHOOK**<br><br>0x0001 | Allows processes running in other accounts on the desktop to set hooks in this process. |

### `fInherit` [in]

If this value is **TRUE**, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `dwDesiredAccess` [in]

The access to the desktop. For a list of access rights, see
[Desktop Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights).

## Return value

If the function succeeds, the return value is a handle to the opened desktop. When you are finished using the handle, call the
[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop) function to close it.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have an associated window station, either assigned by the system at process creation time or set by the
[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation) function.

If the *dwDesiredAccess* parameter specifies the **READ_CONTROL**, **WRITE_DAC**, or **WRITE_OWNER** standard access rights, you must also request the **DESKTOP_READOBJECTS** and **DESKTOP_WRITEOBJECTS** access rights.

> [!NOTE]
> The winuser.h header defines OpenDesktop as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop)

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop)

[SwitchDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-switchdesktop)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)