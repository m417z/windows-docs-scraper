# CreateHardLinkTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Establishes a hard link between an existing file and a new file as a transacted operation.
This function is only supported on the NTFS file system, and only for files, not directories.

## Parameters

### `lpFileName` [in]

The name of the new file.

This parameter cannot specify the name of a directory.

### `lpExistingFileName` [in]

The name of the existing file.

This parameter cannot specify the name of a directory.

### `lpSecurityAttributes`

Reserved; must be **NULL**.

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The maximum number of hard links that can be created with this function is 1023 per file. If more than 1023
links are created for a file, an error results.

The files must reside on the local computer; otherwise,
the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

## Remarks

Any directory entry for a file that is created with
[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda) or
**CreateHardLinkTransacted** is a hard link to an
associated file. An additional hard link that is created with the
**CreateHardLinkTransacted** function allows you to
have multiple directory entries for a file, that is, multiple hard links to the same file, which can be different
names in the same directory, or the same or different names in different directories. However, all hard links to a
file must be on the same volume.

Because hard links are only directory entries for a file, when an application modifies a file through any hard
link, all applications that use any other hard link to the file see the changes. Also, all of the directory
entries are updated if the file changes. For example, if a file size changes, all of the hard links to the file
show the new file size.

The security descriptor belongs to the file to which a hard link points. The link itself is only a directory
entry, and does not have a security descriptor. Therefore, when you change the security descriptor of a hard link,
you a change the security descriptor of the underlying file, and all hard links that point to the file allow the
newly specified access. You cannot give a file different security descriptors on a per-hard-link basis.

This function does not modify the security descriptor of the file to be linked to, even if security descriptor
information is passed in the *lpSecurityAttributes* parameter.

Use [DeleteFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deletefiletransacteda) to delete hard links.
You can delete them in any order regardless of the order in which they are created.

Flags, attributes, access, and sharing that are specified in
[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda) operate on a per-file basis.
That is, if you open a file that does not allow sharing, another application cannot share the file by creating a
new hard link to the file.

When you create a hard link on the NTFS file system, the file attribute information in the directory entry is
refreshed only when the file is opened, or when
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) is called with the
handle of a specific file.

**Symbolic links:** If the path points to a symbolic link, the function creates a hard link to the target.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

Note that SMB 3.0 does not support TxF.

> [!NOTE]
> The winbase.h header defines CreateHardLinkTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda)

[DeleteFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deletefiletransacteda)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[Hard Links and Junctions](https://learn.microsoft.com/windows/desktop/FileIO/hard-links-and-junctions)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)