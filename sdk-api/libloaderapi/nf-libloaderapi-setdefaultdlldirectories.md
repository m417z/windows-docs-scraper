# SetDefaultDllDirectories function

## Description

Specifies a default set of directories to search when the calling process loads a DLL. This search
path is used when [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) is called with no
**LOAD_LIBRARY_SEARCH** flags.

## Parameters

### `DirectoryFlags` [in]

The directories to search. This parameter can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **LOAD_LIBRARY_SEARCH_APPLICATION_DIR**<br><br>0x00000200 | If this value is used, the application's installation directory is searched. |
| **LOAD_LIBRARY_SEARCH_DEFAULT_DIRS**<br><br>0x00001000 | This value is a combination of **LOAD_LIBRARY_SEARCH_APPLICATION_DIR**, **LOAD_LIBRARY_SEARCH_SYSTEM32**, and **LOAD_LIBRARY_SEARCH_USER_DIRS**.<br><br>This value represents the recommended maximum number of directories an application should include in its DLL search path. |
| **LOAD_LIBRARY_SEARCH_SYSTEM32**<br><br>0x00000800 | If this value is used, %windows%\system32 is searched. |
| **LOAD_LIBRARY_SEARCH_USER_DIRS**<br><br>0x00000400 | If this value is used, any path explicitly added using the [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) or [SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya) function is searched. If more than one directory has been added, the order in which those directories are searched is unspecified. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The DLL search path is the set of directories that are searched for a DLL when a full path is not specified in
a [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) or
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) function call, or when a full path to the
DLL is specified but the system must search for dependent DLLs. For more information about the standard DLL search
path, see
[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order).

The standard DLL search path contains directories that can be vulnerable to a
[DLL pre-loading attack](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-security). An application can
use the **SetDefaultDllDirectories** function to
specify a default DLL search path for the process that eliminates the most vulnerable directories and limits the
other directories that are searched. The process DLL search path applies only to the calling process and persists
for the life of the process.

If the *DirectoryFlags* parameter specifies more than one flag, the directories are
searched in the following order:

* The directory that contains the DLL (**LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR**). This
  directory is searched only for dependencies of the DLL being loaded.
* The application directory (**LOAD_LIBRARY_SEARCH_APPLICATION_DIR**).
* Paths explicitly added to the application search path with the
  [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) function
  (**LOAD_LIBRARY_SEARCH_USER_DIRS**) or the
  [SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya) function. If more than one path has
  been added, the order in which the paths are searched is unspecified.
* The System directory (**LOAD_LIBRARY_SEARCH_SYSTEM32**).

If **SetDefaultDllDirectories** does not
specify **LOAD_LIBRARY_SEARCH_USER_DIRS**, directories specified with the
[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) function are used only for
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) function calls that specify
**LOAD_LIBRARY_SEARCH_USER_DIRS**.

It is not possible to revert to the standard DLL search path or remove any directory specified with
**SetDefaultDllDirectories** from the search
path. However, the process DLL search path can be overridden by calling
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) with one or more
**LOAD_LIBRARY_SEARCH** flags, and directories added with
[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) can be removed by calling
[RemoveDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-removedlldirectory).

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** To call this function in an application, use the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to retrieve its address from
Kernel32.dll.
[KB2533623](https://support.microsoft.com/kb/2533623) must be
installed on the target platform.

## See also

[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory)

[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order)

[Dynamic-Link Library Security](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-security)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa)

[RemoveDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-removedlldirectory)