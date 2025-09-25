# MoveFileWithProgressW function

## Description

Moves a file or directory, including its children. You can provide a callback function that receives
progress notifications.

To perform this operation as a transacted operation, use the
[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda) function.

## Parameters

### `lpExistingFileName` [in]

The name of the existing file or directory on the local computer.

If *dwFlags* specifies **MOVEFILE_DELAY_UNTIL_REBOOT**, the
file cannot exist on a remote share because delayed operations are performed before the network is
available.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewFileName` [in, optional]

The new name of the file or directory on the local computer.

When moving a file, *lpNewFileName* can be on a different file system or volume. If
*lpNewFileName* is on another drive, you must set the
**MOVEFILE_COPY_ALLOWED** flag in *dwFlags*.

When moving a directory, *lpExistingFileName* and
*lpNewFileName* must be on the same drive.

If *dwFlags* specifies **MOVEFILE_DELAY_UNTIL_REBOOT** and
*lpNewFileName* is **NULL**,
**MoveFileWithProgress** registers
*lpExistingFileName* to be deleted when the system restarts. The function fails if it
cannot access the registry to store the information about the delete operation. If
*lpExistingFileName* refers to a directory, the system removes the directory at restart
only if the directory is empty.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpProgressRoutine` [in, optional]

A pointer to a [CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine) callback
function that is called each time another portion of the file has been moved. The callback function can be
useful if you provide a user interface that displays the progress of the operation. This parameter can be
**NULL**.

### `lpData` [in, optional]

An argument to be passed to the
[CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine) callback function. This
parameter can be **NULL**.

### `dwFlags` [in]

The move options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MOVEFILE_COPY_ALLOWED**<br><br>2 (0x2) | If the file is to be moved to a different volume, the function simulates the move by using the [CopyFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile) and [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea) functions.<br><br>If the file is successfully copied to a different volume and the original file is unable to be deleted, the function succeeds leaving the source file intact.<br><br>This value cannot be used with **MOVEFILE_DELAY_UNTIL_REBOOT**. |
| **MOVEFILE_CREATE_HARDLINK**<br><br>16 (0x10) | Reserved for future use. |
| **MOVEFILE_DELAY_UNTIL_REBOOT**<br><br>4 (0x4) | The system does not move the file until the operating system is restarted. The system moves the file immediately after AUTOCHK is executed, but before creating any paging files. Consequently, this parameter enables the function to delete paging files from previous startups.<br><br>This value can only be used if the process is in the context of a user who belongs to the administrators group or the LocalSystem account.<br><br>This value cannot be used with **MOVEFILE_COPY_ALLOWED**. |
| **MOVEFILE_FAIL_IF_NOT_TRACKABLE**<br><br>32 (0x20) | The function fails if the source file is a link source, but the file cannot be tracked after the move. This situation can occur if the destination is a volume formatted with the FAT file system. |
| **MOVEFILE_REPLACE_EXISTING**<br><br>1 (0x1) | If a file named *lpNewFileName* exists, the function replaces its contents with the contents of the *lpExistingFileName* file.<br><br>This value cannot be used if *lpNewFileName* or *lpExistingFileName* names a directory. |
| **MOVEFILE_WRITE_THROUGH**<br><br>8 (0x8) | The function does not return until the file has actually been moved on the disk.<br><br>Setting this value guarantees that a move performed as a copy and delete operation is flushed to disk before the function returns. The flush occurs at the end of the copy operation.<br><br>This value has no effect if **MOVEFILE_DELAY_UNTIL_REBOOT** is set. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

When moving a file across volumes, if *lpProgressRoutine* returns
**PROGRESS_CANCEL** due to the user canceling the operation,
**MoveFileWithProgress** will return zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. The existing file is left intact.

When moving a file across volumes, if *lpProgressRoutine* returns
**PROGRESS_STOP** due to the user stopping the operation,
**MoveFileWithProgress** will return zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. The existing file is left intact.

## Remarks

The **MoveFileWithProgress** function coordinates its operation with the link
tracking service, so link sources can be tracked as they are moved.

To delete or rename a file, you must have either delete permission on the file or delete child permission in
the parent directory. If you set up a directory with all access except delete and delete child and the ACLs of new
files are inherited, then you should be able to create a file without being able to delete it. However, you can
then create a file, and you will get all the access you request on the handle returned to you at the time you
create the file. If you requested delete permission at the time you created the file, you could delete or rename
the file with that handle but not with any other.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

CsvFs will do redirected IO for compressed files.

> [!NOTE]
> The winbase.h header defines MoveFileWithProgress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa)

[CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)