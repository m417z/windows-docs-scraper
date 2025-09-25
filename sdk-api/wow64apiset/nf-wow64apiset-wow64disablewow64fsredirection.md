# Wow64DisableWow64FsRedirection function

## Description

Disables file system redirection for the calling thread. File system redirection is enabled by
default.

## Parameters

### `OldValue` [out]

The WOW64 file system redirection value. The system uses this parameter to store information necessary to
revert (re-enable) file system redirection.

**Note** This value is for system use only. To avoid unpredictable behavior, do not modify this value in any
way.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is useful for 32-bit applications that want to gain access to the native system32 directory. By
default, WOW64 file system redirection is enabled.

The
**Wow64DisableWow64FsRedirection**/[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)
function pairing is a replacement for the functionality of the
[Wow64EnableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64enablewow64fsredirection)
function.

To restore file system redirection, call the
[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)
function. Every successful call to the
**Wow64DisableWow64FsRedirection** function
must have a matching call to the
**Wow64RevertWow64FsRedirection**
function. This will ensure redirection is re-enabled and frees associated system resources.

**Note** The **Wow64DisableWow64FsRedirection**
function affects all file operations performed by the current thread, which can have unintended consequences if
file system redirection is disabled for any length of time. For example, DLL loading depends on file system
redirection, so disabling file system redirection will cause DLL loading to fail. Also, many feature
implementations use delayed loading and will fail while redirection is disabled. The failure state of the initial
delay-load operation is persisted, so any subsequent use of the delay-load function will fail even after file
system redirection is re-enabled. To avoid these problems, disable file system redirection immediately before
calls to specific file I/O functions (such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea))
that must not be redirected, and re-enable file system redirection immediately afterward using
[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection).

Disabling file system redirection affects only operations made by the current thread. Some functions, such as
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera), do their work on another
thread, which is not affected by the state of file system redirection in the calling thread.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | No |

#### Examples

The following example uses
**Wow64DisableWow64FsRedirection** to
disable file system redirection so that a 32-bit application that is running under WOW64 can open the 64-bit
version of Notepad.exe in %SystemRoot%\System32 instead of being redirected
to the 32-bit version in %SystemRoot%\SysWOW64.

```cpp
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0501

#ifdef NTDDI_VERSION
#undef NTDDI_VERSION
#endif
#define NTDDI_VERSION 0x05010000

#include <Windows.h>

void main()
{
    HANDLE hFile = INVALID_HANDLE_VALUE;
    PVOID OldValue = NULL;

    //  Disable redirection immediately prior to the native API
    //  function call.
    if( Wow64DisableWow64FsRedirection(&OldValue) )
    {
        //  Any function calls in this block of code should be as concise
        //  and as simple as possible to avoid unintended results.
        hFile = CreateFile(TEXT("C:\\Windows\\System32\\Notepad.exe"),
            GENERIC_READ,
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

        //  Immediately re-enable redirection. Note that any resources
        //  associated with OldValue are cleaned up by this call.
        if ( FALSE == Wow64RevertWow64FsRedirection(OldValue) )
        {
            //  Failure to re-enable redirection should be considered
            //  a critical failure and execution aborted.
            return;
        }
    }

    //  The handle, if valid, now can be used as usual, and without
    //  leaving redirection disabled.
    if( INVALID_HANDLE_VALUE != hFile )
    {
        // Use the file handle
    }
}
```

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File System Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/file-system-redirector)

[Wow64EnableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64enablewow64fsredirection)

[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)