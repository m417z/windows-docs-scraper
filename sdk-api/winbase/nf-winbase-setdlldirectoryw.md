# SetDllDirectoryW function

## Description

Adds a directory to the search path used to locate DLLs for the application.

## Parameters

### `lpPathName` [in, optional]

The directory to be added to the search path. If this parameter is an empty string (""), the call removes the current directory from the default DLL search order. If this parameter is NULL, the function restores the default search order.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetDllDirectory** function affects all subsequent calls to the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) functions. It also effectively disables safe DLL search mode while the specified directory is in the search path.

> [!NOTE]
> For Win32 processes that are **not** running a packaged or protected process, calling this function will also affect the DLL search order of the children processes started from the process that has called the function.

After calling
**SetDllDirectory**, the standard DLL search path is:

1. The directory from which the application loaded.
2. The directory specified by the *lpPathName* parameter.
3. The system directory. Use the
   [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory. The name of this directory is System32.
4. The 16-bit system directory. There is no function that obtains the path of this directory, but it is searched. The name of this directory is System.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable.

Each time the **SetDllDirectory** function is called, it replaces the directory specified in the previous **SetDllDirectory** call. To specify more than one directory, use the [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) function and call [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) with LOAD_LIBRARY_SEARCH_USER_DIRS.

To revert to the standard search path used by
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa), call
**SetDllDirectory** with NULL. This also restores safe DLL search mode based on the **SafeDllSearchMode** registry value.

To compile an application that uses this function, define _WIN32_WINNT as 0x0502 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winbase.h header defines SetDllDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory)

[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order)

[GetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getdlldirectorya)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa)