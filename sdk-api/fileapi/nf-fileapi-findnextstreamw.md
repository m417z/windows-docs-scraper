# FindNextStreamW function

## Description

Continues a stream search started by a previous call to the
[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) function.

## Parameters

### `hFindStream` [in]

The search handle returned by a previous call to the
[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) function.

### `lpFindStreamData` [out]

A pointer to the
[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data) structure that
receives information about the stream.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If no more streams can be found,
**GetLastError** returns
**ERROR_HANDLE_EOF** (38).

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw)

[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data)