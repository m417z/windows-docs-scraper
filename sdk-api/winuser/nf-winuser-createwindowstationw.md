# CreateWindowStationW function

## Description

Creates a window station object, associates it with the calling process, and assigns it to the current session.

## Parameters

### `lpwinsta` [in, optional]

The name of the window station to be created. Window station names are case-insensitive and cannot contain backslash characters (\\). Only members of the Administrators group are allowed to specify a name. If *lpwinsta* is **NULL** or an empty string, the system forms a window station name using the logon session identifier for the calling process. To get this name, call the
[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa) function.

### `dwFlags`

If this parameter is **CWF_CREATE_ONLY** and the window station already exists, the call fails. If this flag is not specified and the window station already exists, the function succeeds and returns a new handle to the existing window station.

**Windows XP/2000:** This parameter is reserved and must be zero.

### `dwDesiredAccess` [in]

The type of access the returned handle has to the window station. In addition, you can specify any of the standard access rights, such as **READ_CONTROL** or **WRITE_DAC**, and a combination of the window station-specific access rights. For more information, see [Window Station Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/window-station-security-and-access-rights).

### `lpsa` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether the returned handle can be inherited by child processes. If *lpsa* is **NULL**, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new window station. If *lpsa* is **NULL**, the window station (and any desktops created within the window) gets a security descriptor that grants **GENERIC_ALL** access to all users.

## Return value

If the function succeeds, the return value is a handle to the newly created window station. If the specified window station already exists, the function succeeds and returns a handle to the existing window station.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After you are done with the handle, you must call
[CloseWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindowstation) to free the handle.

> [!NOTE]
> The winuser.h header defines CreateWindowStation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindowstation)

[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa)

[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)