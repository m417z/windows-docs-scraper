# FindCloseChangeNotification function

## Description

Stops change notification handle monitoring.

## Parameters

### `hChangeHandle` [in]

A handle to a change notification handle created by the
[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the **FindCloseChangeNotification** function is called, the handle
specified by the *hChangeHandle* parameter cannot be used in subsequent calls to either the
[FindNextChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextchangenotification) or
**FindCloseChangeNotification** function.

Change notifications can also be used in the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | See remark |
| Resilient File System (ReFS) | Yes |

Application might experience false positives on CsvFs pause/resume.

## See also

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa)

[FindNextChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextchangenotification)