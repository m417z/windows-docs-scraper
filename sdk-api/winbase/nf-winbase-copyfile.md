# CopyFile function

## Description

Copies an existing file to a new file.

The [CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa) function provides two additional
capabilities. **CopyFileEx** can call a specified callback
function each time a portion of the copy operation is completed, and
**CopyFileEx** can be canceled during the copy operation.

To perform this operation as a transacted operation, use the
[CopyFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfiletransacteda) function.

## Parameters

### `lpExistingFileName` [in]

The name of an existing file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

If *lpExistingFileName* does not exist,
**CopyFile** fails, and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_FILE_NOT_FOUND**.

### `lpNewFileName` [in]

The name of the new file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `bFailIfExists` [in]

If this parameter is **TRUE** and the new file specified by
*lpNewFileName* already exists, the function fails. If this parameter is
**FALSE** and the new file already exists, the function overwrites the existing file and
succeeds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The security resource properties (**ATTRIBUTE_SECURITY_INFORMATION**) for the existing file are
copied to the new file.

**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Security resource properties for the existing file are not copied to the new file until
Windows 8 and Windows Server 2012.

File attributes for the existing file are copied to the new file. For example, if an existing file has the
**FILE_ATTRIBUTE_READONLY** file attribute, a copy created through a call to
**CopyFile** will also have the
**FILE_ATTRIBUTE_READONLY** file attribute. For more information, see
[Retrieving and Changing File Attributes](https://learn.microsoft.com/windows/desktop/FileIO/retrieving-and-changing-file-attributes).

This function fails with **ERROR_ACCESS_DENIED** if the destination file already exists
and has the **FILE_ATTRIBUTE_HIDDEN** or **FILE_ATTRIBUTE_READONLY**
attribute set.

When **CopyFile** is used to copy an encrypted file, it attempts
to encrypt the destination file with the keys used in the encryption of the source file. If this cannot be done,
this function attempts to encrypt the destination file with default keys. If
neither of these methods can be done, **CopyFile** fails with an
**ERROR_ENCRYPTION_FAILED** error code.

Symbolic link behavior—If the source file is a symbolic link, the actual file copied is
the target of the symbolic link.

If the destination file already exists and is a symbolic link, the target of the symbolic link is overwritten
by the source file.

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

[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa)

[CopyFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfiletransacteda)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefile)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)