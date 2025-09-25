# Wow64EnableWow64FsRedirection function

## Description

Enables or disables file system redirection for the calling thread.

This function may not work reliably when there are nested calls. Therefore, this function has been replaced by
the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) and
[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)
functions.

**Note** These two methods of controlling file system redirection cannot be combined in any way. Do not use the
**Wow64EnableWow64FsRedirection**
function with either the
[Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) or the
[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)
function.

## Parameters

### `Wow64FsEnableRedirection`

Indicates the type of request for WOW64 system folder redirection. If
**TRUE**, requests redirection be enabled; if **FALSE**, requests
redirection be disabled.

## Return value

Boolean value indicating whether the function succeeded. If **TRUE**, the function
succeeded; if **FALSE**, the function failed.

## Remarks

This function is useful for 32-bit applications that want to gain access to the native system32 directory. By
default, WOW64 file system redirection is enabled.

**Note** The
**Wow64EnableWow64FsRedirection**
function affects all file operations performed by the current thread, which can have unintended consequences if
file system redirection is disabled for any length of time. For example, DLL loading depends on file system
redirection, so disabling file system redirection will cause DLL loading to fail. Also, many feature
implementations use delayed loading and will fail while redirection is disabled. The failure state of the initial
delay-load operation is persisted, so any subsequent use of the delay-load function will fail even after file
system redirection is re-enabled. To avoid these problems, disable file system redirection immediately before
calls to specific file I/O functions (such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea))
that must not be redirected, and re-enable file system redirection immediately afterward using
`Wow64EnableWow64FsRedirection(TRUE)`.

File redirection is enabled or disabled only for the thread calling this function. This affects only
operations made by the current thread. Some functions, such as
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

### Examples

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

  //  Disable redirection immediately prior to the native API
  //  function call.
  if( Wow64EnableWow64FsRedirection(FALSE) )
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
    if ( FALSE == Wow64EnableWow64FsRedirection(TRUE) )
     {
      //  Failure to re-enable redirection should be considered
      //  a critical failure and execution aborted.
      return;
     }
   }

  // The handle, if valid, can be used as usual without
  // leaving redirection disabled.

  if( INVALID_HANDLE_VALUE != hFile )
   {
    // Use the file handle
   }
 }

```

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File System Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/file-system-redirector)

[GetSystemWow64Directory](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-getsystemwow64directorya)

[Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection)

[Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection)