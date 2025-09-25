# MoveFileW function

## Description

Moves an existing file or a directory, including its children.

To specify how to move the file, use the
[MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa) or
[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa) function.

To perform this operation as a transacted operation, use the
[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda) function.

## Parameters

### `lpExistingFileName` [in]

The current name of the file or directory on the local computer.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewFileName` [in]

The new name for the file or directory. The new name must not already exist. A new file may be on a
different file system or drive. A new directory must be on the same drive.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **MoveFile** function will move (rename) either a file or a
directory (including its children) either in the same directory or across directories. The one caveat is that the
**MoveFile** function will fail on directory moves when the
destination is on a different volume.

 If a file is moved across volumes, **MoveFile** does not move
the security descriptor with the file. The file will be assigned the default security descriptor in the
destination directory.

The **MoveFile** function coordinates its operation with the
link tracking service, so link sources can be tracked as they are moved.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | See comment |
| SMB 3.0 with Scale-out File Shares (SO) | See comment |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB 3.0 does not support rename of alternate data streams on file shares with continuous availability capability.

> [!NOTE]
> The winbase.h header defines MoveFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CopyFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)

[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa)