# GetFileAttributesW function

## Description

Retrieves file system attributes for a specified file or directory.

To get more attribute information, use the
[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) function.

To perform this operation as a transacted operation, use the
[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda) function.

## Parameters

### `lpFileName` [in]

The name of the file or directory.
By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

## Return value

If the function succeeds, the return value contains the attributes of the specified file or directory. For a
list of attribute values and their descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

If the function fails, the return value is **INVALID_FILE_ATTRIBUTES**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When **GetFileAttributes** is called on a directory
that is a mounted folder, it returns the file system attributes of the directory, not those of the root directory
in the volume that the mounted folder associates with the directory. To obtain the file attributes of the
associated volume, call
[GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw) to
obtain the name of the associated volume. Then use the resulting name in a call to
**GetFileAttributes**. The results are the attributes of
the root directory on the associated volume.

If you call **GetFileAttributes** for a network share,
the function fails, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_BAD_NETPATH**. You must specify a path to a subfolder on that share.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

Symbolic link behavior—If the path points to a symbolic link, the function returns
attributes for the symbolic link.

### Transacted Operations

If a file is open for modification in a transaction, no other thread can open the file for modification until
the transaction is committed. So if a transacted thread opens the file first, any subsequent threads that try
modifying the file before the transaction is committed receives a sharing violation. If a non-transacted thread
modifies the file before the transacted thread does, and the file is still open when the transaction attempts to
open it, the transaction receives the error **ERROR_TRANSACTIONAL_CONFLICT**.

#### Examples

For an example, see
[Retrieving and Changing File Attributes](https://learn.microsoft.com/windows/desktop/FileIO/retrieving-and-changing-file-attributes).

> [!NOTE]
> The fileapi.h header defines GetFileAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa)

[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda)

[SetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileattributesa)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)