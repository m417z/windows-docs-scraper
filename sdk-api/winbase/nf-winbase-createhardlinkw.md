# CreateHardLinkW function

## Description

Establishes a hard link between an existing file and a new file. This function is only
supported on the NTFS file system, and only for files, not directories.

To perform this operation as a transacted operation, use the
[CreateHardLinkTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createhardlinktransacteda) function.

## Parameters

### `lpFileName` [in]

The name of the new file.

This parameter may include the path but cannot specify the name of a directory.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpExistingFileName` [in]

The name of the existing file.

This parameter may include the path cannot specify the name of a directory.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpSecurityAttributes`

Reserved; must be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The maximum number of hard links that can be created with this function is 1023 per file. If more than 1023 links are created for a file, an error results.

If you pass a name longer than MAX_PATH characters to the *lpFileName* or *lpExistingFileName* parameter of the ANSI version of this function or to the Unicode version of this function without prepending "\\\\?\\" to the path, the function returns ERROR_PATH_NOT_FOUND.

## Remarks

Any directory entry for a file that is created with
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or
**CreateHardLink** is a hard link to an associated file.
An additional hard link that is created with the
**CreateHardLink**
function allows you to have multiple directory entries for a file, that is, multiple hard links to the same file,
which can be different names in the same directory, or the same or different names in different directories.
However, all hard links to a file must be on the same volume.

Because hard links are only directory entries for a file, many changes to that file are instantly visible to
applications that access it through the hard links that reference it. However, the directory entry size and
attribute information is updated only for the link through which the change was made.

The security descriptor belongs to the file to which a hard link points. The link itself is only a directory
entry, and does not have a security descriptor. Therefore, when you change the security descriptor of a hard link,
you a change the security descriptor of the underlying file, and all hard links that point to the file allow the
newly specified access. You cannot give a file different security descriptors on a per-hard-link basis.

This function does not modify the security descriptor of the file to be linked to, even if security descriptor
information is passed in the *lpSecurityAttributes* parameter.

Use [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea) to delete hard links. You can delete
them in any order regardless of the order in which they are created.

Flags, attributes, access, and sharing that are specified in
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) operate on a per-file basis. That is, if you
open a file that does not allow sharing, another application cannot share the file by creating a new hard link to
the file.

When you create a hard link on the NTFS file system, the file attribute information in the directory entry is
refreshed only when the file is opened, or when
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) is called with
the handle of a specific file.

Symbolic link behavior—If the path points to a symbolic link, the function creates a hard
link to the symbolic link.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | No |

Note that SMB 3.0 does not support creation of hard links on shares with continuous availability capability.

#### Examples

The following code snippet shows you how to call
**CreateHardLink** so that it does not modify the security
descriptor of a file. The *pszExistingFileName* parameter can be the original file name,
or any existing link to a file. After this code is executed, *pszNewLinkName* refers to
the file.

```cpp
  BOOL fCreatedLink = CreateHardLink( pszNewLinkName,
                                      pszExistingFileName,
                                      NULL ); // reserved, must be NULL

  if ( fCreatedLink == FALSE )
   {
    ;// handle error condition
   }

```

> [!NOTE]
> The winbase.h header defines CreateHardLink as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateHardLinkTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createhardlinktransacteda)

[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[Hard Links and Junctions](https://learn.microsoft.com/windows/desktop/FileIO/hard-links-and-junctions)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)