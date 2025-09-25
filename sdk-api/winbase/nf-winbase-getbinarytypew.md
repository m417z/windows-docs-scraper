# GetBinaryTypeW function

## Description

Determines whether a file is an executable (.exe) file, and if so, which subsystem runs the executable
file.

## Parameters

### `lpApplicationName` [in]

The full path of the file whose executable type is to be determined.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpBinaryType` [out]

A pointer to a variable to receive information about the executable type of the file specified by
*lpApplicationName*. The following constants are defined.

| Value | Meaning |
| --- | --- |
| **SCS_32BIT_BINARY**<br><br>0 | A 32-bit Windows-based application |
| **SCS_64BIT_BINARY**<br><br>6 | A 64-bit Windows-based application. |
| **SCS_DOS_BINARY**<br><br>1 | An MS-DOS – based application |
| **SCS_OS216_BINARY**<br><br>5 | A 16-bit OS/2-based application |
| **SCS_PIF_BINARY**<br><br>3 | A PIF file that executes an MS-DOS – based application |
| **SCS_POSIX_BINARY**<br><br>4 | A POSIX – based application |
| **SCS_WOW_BINARY**<br><br>2 | A 16-bit Windows-based application |

## Return value

If the file is executable, the return value is nonzero. The function sets the variable pointed to by
*lpBinaryType* to indicate the file's executable type.

If the file is not executable, or if the function fails, the return value is zero. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the file is a DLL,
the last error code is **ERROR_BAD_EXE_FORMAT**.

## Remarks

As an alternative, you can obtain the same information by calling the
[SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa) function, passing the
**SHGFI_EXETYPE** flag in the *uFlags* parameter.

Symbolic link behavior—If the path points to a symbolic link, the target file is
used.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The winbase.h header defines GetBinaryType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)