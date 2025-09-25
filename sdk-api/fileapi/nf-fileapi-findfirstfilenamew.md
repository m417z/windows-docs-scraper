# FindFirstFileNameW function

## Description

Creates an enumeration of all the hard links to the specified file. The
**FindFirstFileNameW** function returns a handle to the
enumeration that can be used on subsequent calls to the
[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew) function.

To perform this operation as a transacted operation, use the
[FindFirstFileNameTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfilenametransactedw) function.

## Parameters

### `lpFileName` [in]

The name of the file.

**Tip** Starting with Windows 10, version 1607, you can opt-in to remove the **MAX_PATH** limitation without prepending "\\?\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

### `dwFlags` [in]

Reserved; specify zero (0).

### `StringLength` [in, out]

The size of the buffer pointed to by the *LinkName* parameter, in characters. If
this call fails and the error returned from the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function is
**ERROR_MORE_DATA** (234), the value that is returned by this parameter is the size that
the buffer pointed to by *LinkName* must be to contain all the data.

### `LinkName` [in, out]

A pointer to a buffer to store the first link name found for *lpFileName*.

## Return value

If the function succeeds, the return value is a search handle that can be used with the
[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew) function or closed with the
[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose) function.

If the function fails, the return value is **INVALID_HANDLE_VALUE** (0xffffffff). To
get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
function.

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindFirstFileNameTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfilenametransactedw)

[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew)