# GetSystemDirectoryA function

## Description

Retrieves the path of the system directory. The system directory contains system files such as dynamic-link libraries and drivers.

This function is provided primarily for compatibility. Applications should store code in the Program Files folder and persistent data in the Application Data folder in the user's profile. For more information, see
[ShGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha).

## Parameters

### `lpBuffer` [out]

A pointer to the buffer to receive the path. This path does not end with a backslash unless the system directory is the root directory. For example, if the system directory is named Windows\System32 on drive C, the path of the system directory retrieved by this function is C:\Windows\System32.

### `uSize` [in]

The maximum size of the buffer, in **TCHARs**.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the string copied to the buffer, not including the terminating null character. If the length is greater than the size of the buffer, the return value is the size of the buffer required to hold the path, including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications should not create files in the system directory. If the user is running a shared version of the operating system, the application does not have write access to the system directory.

#### Examples

For an example, see
[Getting System Information](https://learn.microsoft.com/windows/desktop/SysInfo/getting-system-information).

> [!NOTE]
> The sysinfoapi.h header defines GetSystemDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrentdirectory)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[SetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcurrentdirectory)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)