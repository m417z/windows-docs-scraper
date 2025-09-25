# SetFileAttributesA function

## Description

Sets the attributes for a file or directory.

To perform this operation as a transacted operation, use the
[SetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfileattributestransacteda) function.

## Parameters

### `lpFileName` [in]

The name of the file whose attributes are to be set.
By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwFileAttributes` [in]

The file attributes to set for the file.

This parameter can be one or more values, combined using the bitwise-OR operator. However, all other values
override **FILE_ATTRIBUTE_NORMAL**.

Not all attributes are supported by this function. For more information, see the Remarks section.

The following is a list of supported attribute values.

| Value | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE**<br><br>32 (0x20) | A file or directory that is an archive file or directory. Applications typically use this attribute to mark files for backup or removal. |
| **FILE_ATTRIBUTE_HIDDEN**<br><br>2 (0x2) | The file or directory is hidden. It is not included in an ordinary directory listing. |
| **FILE_ATTRIBUTE_NORMAL**<br><br>128 (0x80) | A file that does not have other attributes set. This attribute is valid only when used alone. |
| **FILE_ATTRIBUTE_NOT_CONTENT_INDEXED**<br><br>8192 (0x2000) | The file or directory is not to be indexed by the content indexing service. |
| **FILE_ATTRIBUTE_OFFLINE**<br><br>4096 (0x1000) | The data of a file is not available immediately. This attribute indicates that the file data is physically moved to offline storage. This attribute is used by Remote Storage, which is the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| **FILE_ATTRIBUTE_READONLY**<br><br>1 (0x1) | A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not honored on directories. For more information, see "You cannot view or change the Read-only or the System attributes of folders in Windows Server 2003, in Windows XP, or in Windows Vista. |
| **FILE_ATTRIBUTE_SYSTEM**<br><br>4 (0x4) | A file or directory that the operating system uses a part of, or uses exclusively. |
| **FILE_ATTRIBUTE_TEMPORARY**<br><br>256 (0x100) | A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following table describes how to set the attributes that cannot be set using
**SetFileAttributes**. For a complete list of all file
attribute values and their descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

| Attribute | How to Set |
| --- | --- |
| **FILE_ATTRIBUTE_COMPRESSED**<br><br>0x800 | To set a file's compression state, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_COMPRESSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_compression) operation. |
| **FILE_ATTRIBUTE_DEVICE**<br><br>0x40 | Reserved; do not use. |
| **FILE_ATTRIBUTE_DIRECTORY**<br><br>0x10 | Files cannot be converted into directories. To create a directory, use the [CreateDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createdirectorya) or [CreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectoryexa) function. |
| **FILE_ATTRIBUTE_ENCRYPTED**<br><br>0x4000 | To create an encrypted file, use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with the **FILE_ATTRIBUTE_ENCRYPTED** attribute. To convert an existing file into an encrypted file, use the [EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea) function. |
| **FILE_ATTRIBUTE_REPARSE_POINT**<br><br>0x400 | To associate a reparse point with a file or directory, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_reparse_point) operation. |
| **FILE_ATTRIBUTE_SPARSE_FILE**<br><br>0x200 | To set a file's sparse attribute, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse) operation. |

### Transacted Operations

If a file is open for modification in a transaction, no other thread can open the file for modification until
the transaction is committed. So if a transacted thread opens the file first, any subsequent threads that try
modifying the file before the transaction is committed receives a sharing violation. If a non-transacted thread
modifies the file before the transacted thread does, and the file is still open when the transaction attempts to
open it, the transaction receives the error **ERROR_TRANSACTIONAL_CONFLICT**.

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
[Retrieving and Changing File Attributes](https://learn.microsoft.com/windows/desktop/FileIO/retrieving-and-changing-file-attributes).

> [!NOTE]
> The fileapi.h header defines SetFileAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[SetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfileattributestransacteda)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)