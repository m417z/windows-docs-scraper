# FindFirstStreamW function

## Description

Enumerates the first stream with a ::$DATA stream type in the specified file or
directory.

To perform this operation as a transacted operation, use the
[FindFirstStreamTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirststreamtransactedw)
function.

## Parameters

### `lpFileName` [in]

The fully qualified file name.

### `InfoLevel` [in]

The information level of the returned data. This parameter is one of the values in the
[STREAM_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/fileapi/ne-fileapi-stream_info_levels) enumeration type.

| Value | Meaning |
| --- | --- |
| **FindStreamInfoStandard**<br><br>0 | The data is returned in a [WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data) structure. |

### `lpFindStreamData` [out]

A pointer to a buffer that receives the file stream data. The format of this data depends on the value of
the *InfoLevel* parameter.

### `dwFlags`

Reserved for future use. This parameter must be zero.

## Return value

If the function succeeds, the return value is a search handle that can be used in subsequent calls to the
[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw) function.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If no streams can be found, the function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_HANDLE_EOF** (38).
If the filesystem does not support streams, the function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INVALID_PARAMETER** (87).

## Remarks

The **FindFirstStreamW** function opens a search handle and returns information about the first
$DATA stream in the specified file or directory.
For files, this is always the default, unnamed data stream, "::$DATA". Directories do not have $DATA streams by default
and cannot have an unnamed data stream, but may have named data streams set after they have been created.
After the search handle has been established, use it in calls to the
[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw) function to
search for other streams in the specified file or directory. When the search handle is no longer needed, it should
be closed using the [FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose) function.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB 3.0 supports list of streams less than or equal to 64K.

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindFirstStreamTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirststreamtransactedw)

[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw)

[STREAM_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/fileapi/ne-fileapi-stream_info_levels)

[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data)