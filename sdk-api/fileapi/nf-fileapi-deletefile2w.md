## Description

Deletes an existing file.

To perform this operation as a transacted operation, use the [DeleteFileTransacted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-deletefiletransactedw) function.

## Parameters

### `lpFileName`

The name of the file to be deleted.

By default, the name is limited to **MAX_PATH** characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> You can opt-in to remove the **MAX_PATH** limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `Flags`

Flags to specify how to treat the file that is being deleted. This parameter can be a combination one the following values:

| Value | Meaning |
|-------|-------------|
| **FILE_FLAG_DISALLOW_PATH_REDIRECTS**<br>`0x00010000` | Prevent *lpFileName* from being redirected by reparse points or symbolic links. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (`0`). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the following:

| Return code | Description |
|-------------|-------------|
| **ERROR_PATH_REDIRECTED** | *lpFileName* was redirected by reparse points and/or symbolic links. |

## Remarks

If an application attempts to delete a file that does not exist, the **DeleteFile2** function fails with **ERROR_FILE_NOT_FOUND**. If the file is a read-only file, the function fails with **ERROR_ACCESS_DENIED**.

The following list identifies some tips for deleting, removing, or closing files:

- To delete a read-only file, first you must remove the read-only attribute.
- To delete or rename a file, you must have either delete permission on the file, or delete child permission in the parent directory.
- To recursively delete the files in a directory, use the [SHFileOperation](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-shfileoperationw) function.
- To remove an empty directory, use the [RemoveDirectory](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-removedirectoryw) function.
- To close an open file, use the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function.

If you set up a directory with all access except delete and delete child, and the access control lists (ACL) of new files are inherited, then you can create a file without being able to delete it. However, then you can create a file, and then get all the access you request on the handle that is returned to you at the time you create the file.

If you request delete permission at the time you create a file, you can delete or rename the file with that handle, but not with any other handle. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/win32/FileIO/file-security-and-access-rights).

The **DeleteFile2** function fails if an application attempts to delete a file that has other handles open for normal I/O or as a memory-mapped file (**FILE_SHARE_DELETE** must have been specified when other handles were opened).

The **DeleteFile2** function marks a file for deletion on close. Therefore, the file deletion does not occur until the last handle to the file is closed. Subsequent calls to [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew), [CreateFile2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfile2), or [CreateFile3](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfile3) to open the file fail with **ERROR_ACCESS_DENIED**.

The use of POSIX delete causes the file to be deleted while handles remain open. Subsequent calls to [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) to open the file fail with **ERROR_FILE_NOT_FOUND**.

#### Symbolic link behavior

If the path points to a symbolic link, the symbolic link is deleted, not the target. To delete a target, you must call [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) and specify **FILE_FLAG_DELETE_ON_CLOSE**.

This function is supported by the following technologies:

| Technology | Supported |
|------------|-----------|
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The `fileapi.h` header defines **DeleteFile2** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

#### Examples

For an example, see [Locking and Unlocking Byte Ranges in Files](https://learn.microsoft.com/windows/win32/fileio/locking-and-unlocking-byte-ranges-in-files).

## See also

[CreateDirectory2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createdirectory2w)

[CreateFile3](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfile3)

[RemoveDirectory2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-removedirectory2w)