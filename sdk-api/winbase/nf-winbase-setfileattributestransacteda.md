# SetFileAttributesTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Sets the attributes for a file or directory as a transacted operation.

## Parameters

### `lpFileName` [in]

The name of the file whose attributes are to be set.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

### `dwFileAttributes` [in]

The file attributes to set for the file.

For a list of file attribute value and their descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants). This parameter can be
one or more values, combined using the bitwise-OR operator. However, all other values override
**FILE_ATTRIBUTE_NORMAL**.

Not all attributes are supported by this function. For more information, see the Remarks section.

The following is a list of supported attribute values.

#### FILE_ATTRIBUTE_ARCHIVE (32 (0x20))

#### FILE_ATTRIBUTE_HIDDEN (2 (0x2))

#### FILE_ATTRIBUTE_NORMAL (128 (0x80))

#### FILE_ATTRIBUTE_NOT_CONTENT_INDEXED (8192 (0x2000))

#### FILE_ATTRIBUTE_OFFLINE (4096 (0x1000))

#### FILE_ATTRIBUTE_READONLY (1 (0x1))

#### FILE_ATTRIBUTE_SYSTEM (4 (0x4))

#### FILE_ATTRIBUTE_TEMPORARY (256 (0x100))

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following table describes how to set the attributes that cannot be set using
**SetFileAttributesTransacted**. Note that these
are not transacted operations.

| Attribute | How to Set |
| --- | --- |
| **FILE_ATTRIBUTE_COMPRESSED**<br><br>0x800 | To set a file's compression state, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_COMPRESSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_compression) operation. |
| **FILE_ATTRIBUTE_DEVICE**<br><br>0x40 | Reserved; do not use. |
| **FILE_ATTRIBUTE_DIRECTORY**<br><br>0x10 | Files cannot be converted into directories. To create a directory, use the [CreateDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createdirectorya) or [CreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectoryexa) function. |
| **FILE_ATTRIBUTE_ENCRYPTED**<br><br>0x4000 | To create an encrypted file, use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with the **FILE_ATTRIBUTE_ENCRYPTED** attribute. To convert an existing file into an encrypted file, use the [EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea) function. |
| **FILE_ATTRIBUTE_REPARSE_POINT**<br><br>0x400 | To associate a reparse point with a file or directory, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_reparse_point) operation. |
| **FILE_ATTRIBUTE_SPARSE_FILE**<br><br>0x200 | To set a file's sparse attribute, use the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse) operation. |

If a file is open for modification in a transaction, no other thread can successfully open the file for
modification until the transaction is committed. If a transacted thread opens the file first, any subsequent
threads that attempt to open the file for modification before the transaction is committed will receive a sharing
violation. If a non-transacted thread opens the file for modification before the transacted thread does, and it is
still open when the transacted thread attempts to open it, the transaction will receive the
**ERROR_TRANSACTIONAL_CONFLICT** error.

For more information on transactions, see
[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

### Transacted Operations

If a file is open for modification in a transaction, no other thread can open the file for modification until
the transaction is committed. So if a transacted thread opens the file first, any subsequent threads that try
modifying the file before the transaction is committed receives a sharing violation. If a non-transacted thread
modifies the file before the transacted thread does, and the file is still open when the transaction attempts to
open it, the transaction receives the error **ERROR_TRANSACTIONAL_CONFLICT**.

> [!NOTE]
> The winbase.h header defines SetFileAttributesTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)