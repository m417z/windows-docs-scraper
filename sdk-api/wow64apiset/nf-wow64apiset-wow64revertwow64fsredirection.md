# Wow64RevertWow64FsRedirection function

## Description

Restores file system redirection for the calling thread.

This function should not be called without a previous call to the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) function.

Any data allocation on behalf of the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) function is cleaned up by this function.

## Parameters

### `OlValue` [in]

The WOW64 file system redirection value. This value is obtained from the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) function.

This value is defined in `wow64apiset.h`.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is **FALSE** (zero). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection)/**Wow64RevertWow64FsRedirection** function pair is a replacement for the functionality of the [Wow64EnableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64enablewow64fsredirection) function.

To disable file system redirection, call the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) function. Every call to the **Wow64DisableWow64FsRedirection** function must have a matching call to the **Wow64RevertWow64FsRedirection** function. This will ensure redirection is re-enabled and frees associated system resources.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | No |

### Examples

For an example, see the [Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) function.

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File System Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/file-system-redirector)

[Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection)

[Wow64EnableWow64FsRedirection](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-wow64enablewow64fsredirection)