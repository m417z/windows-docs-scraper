# CreateDirectoryTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates a new directory as a transacted operation, with the attributes of a specified template
directory. If the underlying file system supports security on files and directories, the function
applies a specified security descriptor to the new directory. The new directory retains the other attributes of
the specified template directory.

## Parameters

### `lpTemplateDirectory` [in, optional]

The path of the directory to use as a template when creating the new directory. This parameter can be
**NULL**..

The directory must reside on the local computer; otherwise, the function fails and the last error code is set
to **ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewDirectory` [in]

The path of the directory to be created.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details..

### `lpSecurityAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure. The **lpSecurityDescriptor** member of the structure specifies a security
descriptor for the new directory.

If *lpSecurityAttributes* is **NULL**, the directory gets a
default security descriptor. The access control lists (ACL) in the default security descriptor for a directory
are inherited from its parent directory.

The target file system must support security on files and directories for this parameter to have an effect.
This is indicated when [GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)
returns **FS_PERSISTENT_ACLS**.

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the
following.

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified directory already exists. |
| **ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION** | You cannot create a child directory with a parent directory that has encryption disabled. |
| **ERROR_PATH_NOT_FOUND** | One or more intermediate directories do not exist. This function only creates the final directory in the path. |

## Remarks

The **CreateDirectoryTransacted** function
allows you to create directories that inherit stream information from other directories. This function is useful,
for example, when you are using Macintosh directories, which have a resource stream that is needed to properly
identify directory contents as an attribute.

Some file systems, such as the NTFS file system, support compression or encryption for individual files and
directories. On volumes formatted for such a file system, a new directory inherits the compression and encryption
attributes of its parent directory.

This function fails with **ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION** if you try to create a
child directory with a parent directory that has encryption disabled.

You can obtain a handle to a directory by calling the
[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda) function with the
**FILE_FLAG_BACKUP_SEMANTICS** flag set.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

> [!NOTE]
> The winbase.h header defines CreateDirectoryTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda)

[Creating and Deleting Directories](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-deleting-directories)

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[RemoveDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-removedirectorytransacteda)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)