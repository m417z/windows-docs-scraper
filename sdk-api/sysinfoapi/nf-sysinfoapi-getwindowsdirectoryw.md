# GetWindowsDirectoryW function

## Description

Retrieves the
path of the Windows directory.

This function is provided primarily for compatibility with legacy applications. New applications should store code in the Program Files folder
and persistent data in the Application Data folder in the user's profile. For more information, see
[ShGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha).

## Parameters

### `lpBuffer` [out]

A pointer to a buffer that receives the path. This path does not end with a
backslash unless the Windows directory is the root directory. For example, if the Windows directory is named
Windows on drive C, the path of the Windows directory retrieved by this function is C:\Windows. If the system
was installed in the root directory of drive C, the path retrieved is C:\.

### `uSize` [in]

The maximum size of the buffer specified by the *lpBuffer* parameter, in
**TCHARs**. This value should be set to **MAX_PATH**.

## Return value

If the function succeeds, the return value is the length of the string copied to the buffer, in
**TCHARs**, not including the terminating null character.

If the length is greater than the size of the buffer, the return value is the size of the buffer required to
hold the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The Windows directory is the directory where some legacy applications store initialization and help files. New applications should not store files in the Windows directory; instead, they should store system-wide data in the application's installation directory, and user-specific data in the user's profile.

If the
user is running a shared version of the system, the Windows directory is guaranteed to be private for each user.

If an application creates other files that it wants to store on a per-user basis, it should place them in the
directory specified by the HOMEPATH environment variable. This directory will be different for each user, if so
specified by an administrator, through the User Manager administrative tool. HOMEPATH always specifies either the
user's home directory, which is guaranteed to be private for each user, or a default directory (for example,
C:\USERS\DEFAULT) where the user will have all access.

**Terminal Services:** If the application is running in a Terminal Services environment, each user has a private Windows directory.
There is also a shared Windows directory for the system. If the application is Terminal-Services-aware (has the
**IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE** flag set in the image header), this
function returns the path of the system Windows directory, just as the
[GetSystemWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemwindowsdirectorya) function does.
Otherwise, it retrieves the path of the private Windows directory for the user.

#### Examples

For an example, see [Getting System Information](https://learn.microsoft.com/windows/desktop/SysInfo/getting-system-information).

> [!NOTE]
> The sysinfoapi.h header defines GetWindowsDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrentdirectory)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[GetSystemWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemwindowsdirectorya)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)