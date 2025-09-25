# GetFileAttributesTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Retrieves file system attributes for a specified file or directory as a transacted
operation.

## Parameters

### `lpFileName` [in]

The name of the file or directory.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

The file or directory must reside on the local computer; otherwise, the function fails and the last error code is set to **ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

### `fInfoLevelId` [in]

The level of attribute information to retrieve.

This parameter can be the following value from the
[GET_FILEEX_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-get_fileex_info_levels) enumeration.

| Value | Meaning |
| --- | --- |
| **GetFileExInfoStandard** | The *lpFileInformation* parameter is a [WIN32_FILE_ATTRIBUTE_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_file_attribute_data) structure. |

### `lpFileInformation` [out]

A pointer to a buffer that receives the attribute information.

The type of attribute information that is stored into this buffer is determined by the value of
*fInfoLevelId*. If the *fInfoLevelId* parameter is
**GetFileExInfoStandard** then this parameter points to a
[WIN32_FILE_ATTRIBUTE_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_file_attribute_data)
structure

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the [CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When **GetFileAttributesTransacted** is
called on a directory that is a mounted folder, it returns the attributes of the directory, not those of the root directory in the volume that the mounted folder associates with the directory. To obtain the
file attributes of the associated volume, call
[GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw) to
obtain the name of the associated volume. Then use the resulting name in a call to
**GetFileAttributesTransacted**. The results are
the attributes of the root directory on the associated volume.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

**Symbolic links:** If the path points to a symbolic link, the function returns attributes for the symbolic link.

### Transacted Operations

If a file is open for modification in a transaction, no other thread can open the file for modification until
the transaction is committed. Conversely, if a file is open for modification outside of a transaction, no
transacted thread can open the file for modification until the non-transacted handle is closed. If a
non-transacted thread has a handle opened to modify a file, a call to
**GetFileAttributesTransacted** for that file
will fail with an **ERROR_TRANSACTIONAL_CONFLICT** error.

> [!NOTE]
> The winbase.h header defines GetFileAttributesTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfiletransacteda)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[GET_FILEEX_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-get_fileex_info_levels)

[SetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfileattributestransacteda)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)