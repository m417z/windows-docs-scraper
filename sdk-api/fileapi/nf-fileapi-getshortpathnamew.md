# GetShortPathNameW function

## Description

Retrieves the short path form of the specified path.

For more information about file and path names, see
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

## Parameters

### `lpszLongPath` [in]

The path string.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpszShortPath` [out]

A pointer to a buffer to receive the null-terminated short form of the path that
*lpszLongPath* specifies.

Passing **NULL** for this parameter and zero for *cchBuffer*
will always return the required buffer size for a specified *lpszLongPath*.

### `cchBuffer` [in]

The size of the buffer that *lpszShortPath* points to, in
**TCHARs**.

Set this parameter to zero if *lpszShortPath* is set to **NULL**.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the
string that is copied to *lpszShortPath*, not including the terminating null
character.

If the *lpszShortPath* buffer is too small to contain the path, the return value is
the size of the buffer, in **TCHARs**, that is required to hold the path and the
terminating null character.

If the function fails for any other reason, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The path that the *lpszLongPath* parameter specifies does not have to be a full or
long path. The short form can be longer than the specified path.

If the return value is greater than the value specified in the *cchBuffer* parameter,
you can call the function again with a buffer that is large enough to hold the path. For an example of this case
in addition to using zero-length buffer for dynamic allocation, see the Example Code section.

**Note** Although the return value in this case is a length that includes the terminating null character, the return
value on success does not include the terminating null character in the count.

If the specified path is already in its short form and conversion is not needed, the function simply copies
the specified path to the buffer specified by the *lpszShortPath* parameter.

You can set the *lpszShortPath* parameter to the same value as the
*lpszLongPath* parameter; in other words, you can set the output buffer for the short path
to the address of the input path string. Always ensure that the *cchBuffer* parameter
accurately represents the total size, in **TCHARs**, of this buffer.

You can obtain the long name of a file from the short name by calling the
[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea) function. Alternatively, where
**GetLongPathName** is not available, you can call
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) on each component of the path to get the
corresponding long name.

It is possible to have access to a file or directory but not have access to some of the parent directories of
that file or directory. As a result, **GetShortPathName**
may fail when it is unable to query the parent directory of a path component to determine the short name for that
component. This check can be skipped for directory components that already meet the requirements of a short name.
For more information, see the
[Short vs. Long Names](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) section of
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | Yes |

SMB 3.0 does not support short names on shares with continuous availability capability.

Resilient File System (ReFS) doesn't support short names. If you call **GetShortPathName** on a path that doesn't have any short names on-disk, the call will succeed, but will return the long-name path instead. This outcome is also possible with NTFS volumes because there's no guarantee that a short name will exist for a given long name.

#### Examples

For an example that uses **GetShortPathName**, see
the Example Code section for [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea).

The following C++ example shows how to use a dynamically allocated output buffer.

```cpp
//...
    long     length = 0;
    TCHAR*   buffer = NULL;

// First obtain the size needed by passing NULL and 0.

    length = GetShortPathName(lpszPath, NULL, 0);
    if (length == 0) ErrorExit(TEXT("GetShortPathName"));

// Dynamically allocate the correct size
// (terminating null char was included in length)

    buffer = new TCHAR[length];

// Now simply call again using same long path.

    length = GetShortPathName(lpszPath, buffer, length);
    if (length == 0) ErrorExit(TEXT("GetShortPathName"));

    _tprintf(TEXT("long name = %s shortname = %s"), lpszPath, buffer);

    delete [] buffer;
///...

```

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea)

[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea)

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

[SetFileShortName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfileshortnamea)