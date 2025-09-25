# RemoveDllDirectory function

## Description

Removes a directory that was added to the process DLL search path by using
[AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory).

## Parameters

### `Cookie` [in]

The cookie returned by [AddDllDirectory](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-adddlldirectory) when the
directory was added to the search path.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value
is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After **RemoveDllDirectory** returns, the cookie is
no longer valid and should not be used.

**Windows 7, Windows Server 2008 R2, Windows Vista and Windows Server 2008:** To call this function in an application, use the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to retrieve its address from
Kernel32.dll.
[KB2533623](https://support.microsoft.com/kb/2533623) must be
installed on the target platform.