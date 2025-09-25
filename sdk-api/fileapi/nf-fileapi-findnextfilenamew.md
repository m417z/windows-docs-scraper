# FindNextFileNameW function

## Description

Continues enumerating the hard links to a file using the handle returned by a successful call to the
[FindFirstFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilenamew) function.

## Parameters

### `hFindStream` [in]

A handle to the enumeration that is returned by a successful call to
[FindFirstFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilenamew).

### `StringLength` [in, out]

The size of the *LinkName* parameter, in characters. If this call fails and the
error is **ERROR_MORE_DATA**, the value that is returned by this parameter is the size
that *LinkName* must be to contain all the data.

### `LinkName` [in, out]

A pointer to a buffer to store the first link name found for *lpFileName*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If no matching files can be found, the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
function returns **ERROR_HANDLE_EOF**.

## Remarks

If the function returns **TRUE**, there are more hard links to enumerate.

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

[FindFirstFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilenamew)