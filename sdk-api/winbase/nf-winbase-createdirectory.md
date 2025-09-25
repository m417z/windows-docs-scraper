# CreateDirectory function

## Description

Creates a new directory. If the underlying file system supports security on files and
directories, the function applies a specified security descriptor to the new directory.

To specify a template directory, use the
[CreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectoryexa) function.

To perform this
operation as a transacted operation, use the
[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda) function.

## Parameters

### `lpPathName` [in]

The path of the directory to be created.

For the ANSI version of this function, there is a default string size limit for paths of 248 characters (**MAX_PATH** - enough room for a 8.3 filename). To extend this limit to 32,767 wide characters, call the Unicode version of the function and prepend
"\\?\" to the path. For more information, see
[Naming a File](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

**Tip** Starting with Windows 10, version 1607, for the unicode version of this function (**CreateDirectoryW**), you can opt-in to remove the 248 character limitation without prepending "\\?\". The 255 character limit per path segment still applies. See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

### `lpSecurityAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure. The **lpSecurityDescriptor** member of the structure specifies a security
descriptor for the new directory. If *lpSecurityAttributes* is
**NULL**, the directory gets a default security descriptor. The ACLs in the default
security descriptor for a directory are inherited from its parent directory.

The target file system must support security on files and directories for this parameter to have an effect.
(This is indicated when [GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)
returns **FS_PERSISTENT_ACLS**.)

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the
following.

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified directory already exists. |
| **ERROR_PATH_NOT_FOUND** | One or more intermediate directories do not exist; this function will only create the final directory in the path. |

## Remarks

Some file systems, such as the NTFS file system, support compression or encryption for individual files and
directories. On volumes formatted for such a file system, a new directory inherits the compression and encryption
attributes of its parent directory.

An application can obtain a handle to a directory by calling
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
**FILE_FLAG_BACKUP_SEMANTICS** flag set. For a code example, see
**CreateFile**.

To support inheritance functions that query the security descriptor of this object may heuristically determine
and report that inheritance is in effect. See
[Automatic Propagation of Inheritable ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/automatic-propagation-of-inheritable-aces)
for more information.

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

## See also

[CreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectoryexa)

[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Creating and Deleting Directories](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-deleting-directories)

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[RemoveDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-removedirectorya)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)