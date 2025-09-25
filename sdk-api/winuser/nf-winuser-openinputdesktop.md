# OpenInputDesktop function

## Description

Opens the desktop that receives user input.

## Parameters

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

If the function succeeds, the return value is a handle to the desktop that receives user input. When you are finished using the handle, call the
[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop) function to close it.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have an associated window station, either assigned by the system when the process is created, or set by
the [SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation) function. The window station associated with the calling process must be capable of receiving input.

If the calling process is running in a disconnected session, the function returns a handle to the desktop that becomes active when the user restores the connection.

An application can use the
[SwitchDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-switchdesktop) function to change the input desktop.

If the *dwDesiredAccess* parameter specifies the **READ_CONTROL**, **WRITE_DAC**, or **WRITE_OWNER** standard access rights, you must also request the **DESKTOP_READOBJECTS** and **DESKTOP_WRITEOBJECTS** access rights.

## See also

[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[SwitchDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-switchdesktop)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)