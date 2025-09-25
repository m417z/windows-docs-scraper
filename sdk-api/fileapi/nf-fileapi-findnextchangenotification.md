# FindNextChangeNotification function

## Description

Requests that the operating system signal a change notification handle the next time it detects an appropriate change.

## Parameters

### `hChangeHandle` [in]

A handle to a change notification handle created by the
[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the
**FindNextChangeNotification** function returns successfully, the application can wait for notification that a change has occurred by using the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

If a change occurs after a call to
[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) but before a call to
**FindNextChangeNotification**, the operating system records the change. When
**FindNextChangeNotification** is executed, the recorded change immediately satisfies a wait for the change notification.

Each successful call to **FindNextChangeNotification** must be followed by a call to one of the wait functions. If the wait function returns for any reason other than the change notification handle being signaled (for example, if the wait times out), the application must retry the wait. Failing to follow this rule can cause the system to eventually run out of resources. It can also cause the application to miss some change notifications.

When *hChangeHandle* is no longer needed, close it by using the
[FindCloseChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclosechangenotification) function.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | See remark |
| Resilient File System (ReFS) | Yes |

Application might experience false positives on CsvFs pause/resume.

#### Examples

For an example, see
[Obtaining Directory Change Notifications](https://learn.microsoft.com/windows/desktop/FileIO/obtaining-directory-change-notifications).

## See also

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[FindCloseChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclosechangenotification)

[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa)