# GetLongPathNameW function

## Description

Converts the specified path to its long form.

To perform this operation as a transacted operation, use the
[GetLongPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getlongpathnametransacteda) function.

For more information about file and path names, see
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

> [!IMPORTANT]
> To use this function, the caller must have the following permissions on the specified path and parent directories:
> - List Folder
> - Read Data
> - Read Attributes

## Parameters

### `lpszShortPath` [in]

The path to be converted.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpszLongPath` [out]

A pointer to the buffer to receive the long path.

You can use the same buffer you used for the *lpszShortPath* parameter.

### `cchBuffer` [in]

The size of the buffer *lpszLongPath* points to, in
**TCHARs**.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the
string copied to *lpszLongPath*, not including the terminating null character.

If the *lpszLongPath* buffer is too small to contain the path, the return value is the
size, in **TCHARs**, of the buffer that is required to hold the path and the
terminating null character.

If the function fails for any other reason, such as if the file does not
exist, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On many file systems, a short file name contains a tilde (~) character. However, not all file systems follow
this convention. Therefore, do not assume that you can skip calling
**GetLongPathName** if the path does not contain a tilde (~)
character.

If the file or directory exists but a long path is not found,
**GetLongPathName** succeeds, having copied the string
referred to by the *lpszShortPath* parameter to the buffer referred to by the
*lpszLongPath* parameter.

If the return value is greater than the value specified in *cchBuffer*, you can call
the function again with a buffer that is large enough to hold the path. For an example of this case, see the
Example Code section for [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea).

**Note** Although the return value in this case is a length that includes the terminating null character, the return
value on success does not include the terminating null character in the count.

It is possible to have access to a file or directory but not have access to some of the parent directories of
that file or directory. As a result, **GetLongPathName** may
fail when it is unable to query the parent directory of a path component to determine the long name for that
component. This check can be skipped for directory components that have file extensions longer than 3 characters,
or total lengths longer than 12 characters. For more information, see the
[Short vs. Long Names](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) section of
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example that uses **GetLongPathName**, see the
Example Code section for [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea).

> [!NOTE]
> The fileapi.h header defines GetLongPathName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea)

[GetLongPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getlongpathnametransacteda)

[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew)

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)