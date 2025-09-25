# CreateDesktopExA function

## Description

Creates a new desktop with the specified heap, associates it with the current window station of the calling process, and assigns it to the calling thread. The calling process must have an associated window station, either assigned by the system at process creation time or set by
the [SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation) function.

## Parameters

### `lpszDesktop` [in]

The name of the desktop to be created. Desktop names are case-insensitive and may not contain backslash characters (\\).

### `lpszDevice`

This parameter is reserved and must be NULL.

### `pDevmode`

This parameter is reserved and must be NULL.

### `dwFlags` [in]

This parameter can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **DF_ALLOWOTHERACCOUNTHOOK**<br><br>0x0001 | Enables processes running in other accounts on the desktop to set hooks in this process. |

### `dwDesiredAccess` [in]

The requested access to the desktop. For a list of values, see
[Desktop Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights).

This parameter must include the DESKTOP_CREATEWINDOW access right, because internally
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa) uses the handle to create a window.

### `lpsa` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether the returned handle can be inherited by child processes. If *lpsa* is NULL, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new desktop. If this parameter is NULL, the desktop inherits its security descriptor from the parent window station.

### `ulHeapSize` [in]

The size of the desktop heap, in kilobytes.

### `pvoid`

This parameter is reserved and must be NULL.

## Return value

If the function succeeds, the return value is a handle to the newly created desktop. If the specified desktop already exists, the function succeeds and returns a handle to the existing desktop. When you are finished using the handle, call the
[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop) function to close it.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *dwDesiredAccess* parameter specifies the READ_CONTROL, WRITE_DAC, or WRITE_OWNER standard access rights, you must also request the DESKTOP_READOBJECTS and DESKTOP_WRITEOBJECTS access rights.

The number of desktops that can be created is limited by the size of the system desktop heap. Desktop objects use the heap to store resources. You can increase the number of desktops that can be created by increasing the size of the desktop heap or by reducing the default heap reserved for each desktop in the interactive window station. This value is specified in the SharedSection substring of the following registry value: **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\SubSystems\Windows**. The default data for this registry value is as follows:

%SystemRoot%\system32\csrss.exe ObjectDirectory=\Windows
SharedSection=1024,3072,512 Windows=On SubSystemType=Windows
ServerDll=basesrv,1 ServerDll=winsrv:UserServerDllInitialization,3
ServerDll=winsrv:ConServerDllInitialization,2 ProfileControl=Off
MaxRequestThreads=16

The values for the SharedSection substring are described as follows:

* The first SharedSection value is the size of the shared heap common to all desktops, in kilobytes.
* The second SharedSection value is the size of the desktop heap needed for each desktop that is created in the interactive window station, WinSta0, in kilobytes.
* The third SharedSection value is the size of the desktop heap needed for each desktop that is created in a noninteractive window station, in kilobytes.

The default size of the desktop heap depends on factors such as hardware architecture. To retrieve the size of the desktop heap, call the [GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa) function with UOI_HEAPSIZE.

> [!NOTE]
> The winuser.h header defines CreateDesktopEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[SwitchDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-switchdesktop)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)