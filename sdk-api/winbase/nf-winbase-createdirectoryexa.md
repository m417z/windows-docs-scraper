# CreateDirectoryExA function

## Description

Creates a new directory with the attributes of a specified template directory. If the
underlying file system supports security on files and directories, the function applies a specified security
descriptor to the new directory. The new directory retains the other attributes of the specified template
directory.

To perform this operation as a transacted operation, use the
[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda) function.

## Parameters

### `lpTemplateDirectory` [in]

The path of the directory to use as a template when creating the new directory.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewDirectory` [in]

The path of the directory to be created.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

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

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the
following.

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified directory already exists. |
| **ERROR_PATH_NOT_FOUND** | One or more intermediate directories do not exist. This function only creates the final directory in the path. To create all intermediate directories on the path, use the [SHCreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedirectoryexa) function. |

## Remarks

The **CreateDirectoryEx** function allows you to
create directories that inherit stream information from other directories. This function is useful, for example,
when you are using Macintosh directories, which have a resource stream that is needed to properly identify
directory contents as an attribute.

Some file systems, such as the NTFS file system, support compression or encryption for individual files and
directories. On volumes formatted for such a file system, a new directory inherits the compression and encryption
attributes of its parent directory.

You can obtain a handle to a directory by calling the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with the
**FILE_FLAG_BACKUP_SEMANTICS** flag set. For a code example, see
**CreateFile**.

To support inheritance functions that query the security descriptor of this
object can heuristically determine and report that inheritance is in effect. For more information, see
[Automatic Propagation of Inheritable ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/automatic-propagation-of-inheritable-aces).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The winbase.h header defines CreateDirectoryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createdirectorya)

[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Creating and Deleting Directories](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-deleting-directories)

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[RemoveDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-removedirectorya)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)