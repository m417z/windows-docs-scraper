# MoveFileExW function

## Description

Moves an existing file or directory, including its children, with various move options.

The [MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa) function is equivalent
to the **MoveFileEx** function, except that
**MoveFileWithProgress** allows you to provide a
callback function that receives progress notifications.

To perform this operation as a transacted operation, use the
[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda) function.

## Parameters

### `lpExistingFileName` [in]

The current name of the file or directory on the local computer.

If *dwFlags* specifies **MOVEFILE_DELAY_UNTIL_REBOOT**, the
file cannot exist on a remote share, because delayed operations are performed before the network is
available.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewFileName` [in, optional]

The new name of the file or directory on the local computer.

When moving a file, the destination can be on a different file system or volume. If the destination is on
another drive, you must set the **MOVEFILE_COPY_ALLOWED** flag in
*dwFlags*.

When moving a directory, the destination must be on the same drive.

If *dwFlags* specifies **MOVEFILE_DELAY_UNTIL_REBOOT** and
*lpNewFileName* is **NULL**,
**MoveFileEx** registers the
*lpExistingFileName* file to be deleted when the system restarts. If
*lpExistingFileName* refers to a directory, the system removes the directory at restart
only if the directory is empty.

In the ANSI version of this function, the name is limited to **MAX_PATH** characters.
To extend this limit to 32,767 wide characters, call the Unicode version of the function and prepend
"\\?\" to the path. For more information, see
[Naming a File](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwFlags` [in]

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MOVEFILE_COPY_ALLOWED**<br><br>2 (0x2) | If the file is to be moved to a different volume, the function simulates the move by using the [CopyFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile) and [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea) functions.<br><br>If the file is successfully copied to a different volume and the original file is unable to be deleted, the function succeeds leaving the source file intact.<br><br>This value cannot be used with **MOVEFILE_DELAY_UNTIL_REBOOT**. |
| **MOVEFILE_CREATE_HARDLINK**<br><br>16 (0x10) | Reserved for future use. |
| **MOVEFILE_DELAY_UNTIL_REBOOT**<br><br>4 (0x4) | The system does not move the file until the operating system is restarted. The system moves the file immediately after AUTOCHK is executed, but before creating any paging files. Consequently, this parameter enables the function to delete paging files from previous startups.<br><br>This value can be used only if the process is in the context of a user who belongs to the administrators group or the LocalSystem account.<br><br>This value cannot be used with **MOVEFILE_COPY_ALLOWED**. |
| **MOVEFILE_FAIL_IF_NOT_TRACKABLE**<br><br>32 (0x20) | The function fails if the source file is a link source, but the file cannot be tracked after the move. This situation can occur if the destination is a volume formatted with the FAT file system. |
| **MOVEFILE_REPLACE_EXISTING**<br><br>1 (0x1) | If a file named *lpNewFileName* exists, the function replaces its contents with the contents of the *lpExistingFileName* file, provided that security requirements regarding access control lists (ACLs) are met. For more information, see the Remarks section of this topic.<br><br>If *lpNewFileName* names an existing directory, an error is reported. |
| **MOVEFILE_WRITE_THROUGH**<br><br>8 (0x8) | The function does not return until the file is actually moved on the disk.<br><br>Setting this value guarantees that a move performed as a copy and delete operation is flushed to disk before the function returns. The flush occurs at the end of the copy operation.<br><br>This value has no effect if **MOVEFILE_DELAY_UNTIL_REBOOT** is set. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *dwFlags* parameter specifies
**MOVEFILE_DELAY_UNTIL_REBOOT**,
**MoveFileEx** fails if it cannot access the registry. The
function stores the locations of the files to be renamed at restart in the following registry value:
**HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Control**\**Session Manager**\**PendingFileRenameOperations**

This registry value is of type **REG_MULTI_SZ**. Each rename operation stores one
of the following NULL-terminated strings, depending on whether the rename is a delete or not:

* *szSrcFile*\0\0
* *szSrcFile*\0*szDstFile*\0

The string *szSrcFile*\0\0 indicates that the file
*szSrcFile* is to be deleted on reboot. The string
*szSrcFile*\0*szDstFile*\0 indicates that
*szSrcFile* is to be renamed *szDstFile* on reboot.

**Note** Although \0\0 is technically not allowed in a **REG_MULTI_SZ** node, it can because
the file is considered to be renamed to a null name.

The system uses these registry entries to complete the operations at restart in the same order that they were
issued. For example, the following code fragment creates registry entries that delete
*szSrcFile* and rename *szSrcFile* to be
*szDstFile* at restart:

```cpp
MoveFileEx(szSrcFile, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
MoveFileEx(szSrcFile, szDstFile, MOVEFILE_DELAY_UNTIL_REBOOT);

```

Because the actual move and deletion operations specified with the
**MOVEFILE_DELAY_UNTIL_REBOOT** flag take place after the calling application has ceased
running, the return value cannot reflect success or failure in moving or deleting the file. Rather, it reflects
success or failure in placing the appropriate entries into the registry.

The system deletes a directory that is tagged for deletion with the
**MOVEFILE_DELAY_UNTIL_REBOOT** flag only if it is empty. To ensure deletion of directories,
move or delete all files from the directory before attempting to delete it. Files may be in the directory at boot
time, but they must be deleted or moved before the system can delete the directory.

The move and deletion operations are carried out at boot time in the same order that they are specified in the
calling application. To delete a directory that has files in it at boot time, first delete the files.

If a file is moved across volumes, **MoveFileEx** does not
move the security descriptor with the file. The file is assigned the default security descriptor in the
destination directory.

The **MoveFileEx** function coordinates its operation with
the [link tracking](https://learn.microsoft.com/windows/desktop/FileIO/distributed-link-tracking-and-object-identifiers) service,
so link sources can be tracked as they are moved.

To delete or rename a file, you must have either delete permission on the file or delete child permission in
the parent directory. If you set up a directory with all access except delete and delete child and the ACLs of
new files are inherited, then you should be able to create a file without being able to delete it. However, you
can then create a file, and get all the access you request on the handle that is returned to you at the time that
you create the file. If you request delete permission at the time you create the file, you can delete or rename
the file with that handle but not with any other handle. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Creating and Using a Temporary File](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-using-a-temporary-file).

## See also

[CopyFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile)

[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)

[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa)

[WritePrivateProfileString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa)