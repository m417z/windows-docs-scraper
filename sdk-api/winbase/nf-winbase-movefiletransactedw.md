# MoveFileTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Moves an existing file or a directory, including its children, as a transacted
operation.

## Parameters

### `lpExistingFileName` [in]

The current name of the existing file or directory on the local computer.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewFileName` [in, optional]

The new name for the file or directory. The new name must not already exist. A new file may be on a
different file system or drive. A new directory must be on the same drive.

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
| **MOVEFILE_DELAY_UNTIL_REBOOT**<br><br>4 (0x4) | The system does not move the file until the operating system is restarted. The system moves the file immediately after AUTOCHK is executed, but before creating any paging files. Consequently, this parameter enables the function to delete paging files from previous startups.<br><br>This value can only be used if the process is in the context of a user who belongs to the administrators group or the LocalSystem account.<br><br>This value cannot be used with **MOVEFILE_COPY_ALLOWED**.<br><br>The write operation to the registry value as detailed in the Remarks section is what is transacted. The file move is finished when the computer restarts, after the transaction is complete. |
| **MOVEFILE_REPLACE_EXISTING**<br><br>1 (0x1) | If a file named *lpNewFileName* exists, the function replaces its contents with the contents of the *lpExistingFileName* file.<br><br>This value cannot be used if *lpNewFileName* or *lpExistingFileName* names a directory. |
| **MOVEFILE_WRITE_THROUGH**<br><br>8 (0x8) | A call to **MoveFileTransacted** means that the move file operation is complete when the commit operation is completed. This flag is unnecessary; there are no negative affects if this flag is specified, other than an operation slowdown. The function does not return until the file has actually been moved on the disk.<br><br>Setting this value guarantees that a move performed as a copy and delete operation is flushed to disk before the function returns. The flush occurs at the end of the copy operation.<br><br>This value has no effect if **MOVEFILE_DELAY_UNTIL_REBOOT** is set. |

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

When moving a file across volumes, if *lpProgressRoutine* returns
**PROGRESS_CANCEL** due to the user canceling the operation,
**MoveFileTransacted** will return zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. The existing file is left intact.

When moving a file across volumes, if *lpProgressRoutine* returns
**PROGRESS_STOP** due to the user stopping the operation,
**MoveFileTransacted** will return zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. The existing file is left intact.

## Remarks

If the *dwFlags* parameter specifies
**MOVEFILE_DELAY_UNTIL_REBOOT**,
**MoveFileTransacted** fails if it cannot access the registry. The
function transactionally stores the locations of the files to be renamed at restart in the following registry
value:
**HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Control**\**Session Manager**\**PendingFileRenameOperations**

This registry value is of type **REG_MULTI_SZ**. Each rename operation stores one of
the following **NULL**-terminated strings, depending on whether the rename is a delete or
not:

*szDstFile*\0\0

*szSrcFile*\0*szDstFile*\0

The string *szDstFile*\0\0 indicates that the file
*szDstFile* is to be deleted on reboot.

The string *szSrcFile*\0*szDstFile*\0 indicates that
*szSrcFile* is to be renamed *szDstFile* on reboot.

**Note** Although \0\0 is technically not allowed in a **REG_MULTI_SZ** node, it can because
the file is considered to be renamed to a null name.

The system uses these registry entries to complete the operations at restart in the same order that they were
issued. For more information about using the **MOVEFILE_DELAY_UNTIL_REBOOT** flag, see
[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa).

 If a file is moved across volumes,
**MoveFileTransacted** does not move the security
descriptor with the file. The file is assigned the default security descriptor in the destination directory.

This function always fails if you specify the **MOVEFILE_FAIL_IF_NOT_TRACKABLE** flag;
tracking is not supported by TxF.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

## See also

[CopyFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfiletransacteda)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)