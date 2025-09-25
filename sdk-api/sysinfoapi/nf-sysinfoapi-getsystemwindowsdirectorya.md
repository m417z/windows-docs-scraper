# GetSystemWindowsDirectoryA function

## Description

Retrieves the path of the shared Windows directory on a multi-user system.

This function is provided primarily for compatibility. Applications should store code in the Program Files folder and persistent data in the Application Data folder in the user's profile. For more information, see
[ShGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha).

## Parameters

### `lpBuffer` [out]

A pointer to the buffer to receive the path. This path does not end with a backslash unless the Windows directory is the root directory. For example, if the Windows directory is named Windows on drive C, the path of the Windows directory retrieved by this function is C:\Windows. If the system was installed in the root directory of drive C, the path retrieved is C:\.

### `uSize` [in]

The maximum size of the buffer specified by the *lpBuffer* parameter, in **TCHARs**.

## Return value

If the function succeeds, the return value is the length of the string copied to the buffer, in **TCHARs**, not including the terminating null character.

If the length is greater than the size of the buffer, the return value is the size of the buffer required to hold the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On a system that is running Terminal Services, each user has a unique Windows directory. The system Windows directory is shared by all users, so it is the directory where an application should store initialization and help files that apply to all users.

With Terminal Services, the
**GetSystemWindowsDirectory** function retrieves the path of the system Windows directory, while the
[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function retrieves the path of a Windows directory that is private for each user. On a single-user system,
**GetSystemWindowsDirectory** is the same as
**GetWindowsDirectory**.

> [!NOTE]
> The sysinfoapi.h header defines GetSystemWindowsDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)