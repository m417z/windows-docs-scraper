# FindFirstStreamTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Enumerates the first stream in the specified file or directory as a transacted
operation.

## Parameters

### `lpFileName` [in]

The fully qualified file name.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE** (6805).

### `InfoLevel` [in]

The information level of the returned data. This parameter is one of the values in the
[STREAM_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/fileapi/ne-fileapi-stream_info_levels) enumeration type.

| Value | Meaning |
| --- | --- |
| **FindStreamInfoStandard**<br><br>0 | The data is returned in a [WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data) structure. |

### `lpFindStreamData` [out]

A pointer to a buffer that receives the file data. The format of this data depends on the value of
the *InfoLevel* parameter.

### `dwFlags`

Reserved for future use. This parameter must be zero.

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is a search handle that can be used in subsequent calls to the
[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw) function.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All files contain a default data stream. On NTFS, files can also contain one or more named data streams. On
FAT file systems, files cannot have more that the default data stream, and therefore, this function will not
return valid results when used on FAT filesystem files. This function works on all file systems that supports hard
links; otherwise, the function returns **ERROR_STATUS_NOT_IMPLEMENTED** (6805).

The **FindFirstStreamTransactedW** function
opens a search handle and returns information about the first stream in the specified file or directory. For
files, this is always the default data stream, ::$DATA. After the search handle has been established, use it in
the [FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw) function to search for other
streams in the specified file or directory. When the search handle is no longer needed, it should be closed using
the [FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose) function.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw)

[STREAM_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/fileapi/ne-fileapi-stream_info_levels)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)

[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data)