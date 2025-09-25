# AddDllDirectory function

## Description

Adds a directory to the process DLL search path.

## Parameters

### `NewDirectory` [in]

An absolute path to the directory to add to the search path. For example, to add the directory
Dir2 to the process DLL search path, specify \Dir2. For more information about paths,
see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

## Return value

If the function succeeds, the return value is an opaque pointer that can be passed to
[RemoveDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-removedlldirectory) to remove the DLL from the
process DLL search path.

If the function fails, the return value is zero. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **AddDllDirectory** function can be used to add
any absolute path to the set of directories that are searched for a DLL. If
[SetDefaultDllDirectories](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-setdefaultdlldirectories) is first called with
**LOAD_LIBRARY_SEARCH_USER_DIRS**, directories specified with
**AddDllDirectory** are added to the process DLL search
path. Otherwise, directories specified with the
**AddDllDirectory** function are used only for
[LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) function calls that specify
**LOAD_LIBRARY_SEARCH_USER_DIRS**.

If **AddDllDirectory** is used to add more than one
directory to the process DLL search path, the order in which those directories are searched is unspecified.

To remove a directory added with **AddDllDirectory**,
use the [RemoveDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-removedlldirectory) function.

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** To use this function in an application, call
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to retrieve the function's address
from Kernel32.dll.
[KB2533623](https://support.microsoft.com/kb/2533623) must be
installed on the target platform.