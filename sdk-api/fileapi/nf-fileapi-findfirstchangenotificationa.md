# FindFirstChangeNotificationA function

## Description

Creates a change notification handle and sets up initial change notification filter conditions. A wait on a notification handle succeeds when a change matching the filter conditions occurs in the specified directory or subtree. The function does not report changes to the specified directory itself.

This function does not indicate the change that satisfied the wait condition. To retrieve information about the specific change as part of the notification, use the
[ReadDirectoryChangesW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesw) function.

## Parameters

### `lpPathName` [in]

The full path of the directory to be watched.

This cannot be a relative path or an empty string.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `bWatchSubtree` [in]

If this parameter is **TRUE**, the function monitors the directory tree rooted at the specified directory; if it is **FALSE**, it monitors only the specified directory.

### `dwNotifyFilter` [in]

The filter conditions that satisfy a change notification wait. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_NOTIFY_CHANGE_FILE_NAME**<br><br>0x00000001 | Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file name. |
| **FILE_NOTIFY_CHANGE_DIR_NAME**<br><br>0x00000002 | Any directory-name change in the watched directory or subtree causes a change notification wait operation to return. Changes include creating or deleting a directory. |
| **FILE_NOTIFY_CHANGE_ATTRIBUTES**<br><br>0x00000004 | Any attribute change in the watched directory or subtree causes a change notification wait operation to return. |
| **FILE_NOTIFY_CHANGE_SIZE**<br><br>0x00000008 | Any file-size change in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change in file size only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed. |
| **FILE_NOTIFY_CHANGE_LAST_WRITE**<br><br>0x00000010 | Any change to the last write-time of files in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change to the last write-time only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed. |
| **FILE_NOTIFY_CHANGE_SECURITY**<br><br>0x00000100 | Any security-descriptor change in the watched directory or subtree causes a change notification wait operation to return. |

## Return value

If the function succeeds, the return value is a handle to a find change notification object.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) can monitor the specified directory or subtree by using the handle returned by the
**FindFirstChangeNotification** function. A wait is satisfied when one of the filter conditions occurs in the monitored directory or subtree.

After the wait has been satisfied, the application can respond to this condition and continue monitoring the directory by calling the
[FindNextChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextchangenotification) function and the appropriate wait function. When the handle is no longer needed, it can be closed by using the
[FindCloseChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclosechangenotification) function.

Notifications may not be returned when calling **FindFirstChangeNotification** for a remote file system.

Symbolic link behavior—If the path points to a symbolic link, the notification handle is created for the target.

If an application has registered to receive change notifications for a directory that contains symbolic links, the application is only notified when the symbolic links have been changed, not the target files.

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
[Obtaining Directory Change_Notifications](https://learn.microsoft.com/windows/desktop/FileIO/obtaining-directory-change-notifications).

> [!NOTE]
> The fileapi.h header defines FindFirstChangeNotification as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[FindCloseChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclosechangenotification)

[FindNextChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextchangenotification)

[ReadDirectoryChangesW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesw)