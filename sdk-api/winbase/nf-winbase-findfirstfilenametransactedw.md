# FindFirstFileNameTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates an enumeration of all the hard links to the specified file as a transacted operation. The
function returns a handle to the enumeration that can be used on subsequent calls to the
[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew) function.

## Parameters

### `lpFileName` [in]

The name of the file.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE** (6805).

### `dwFlags` [in]

Reserved; specify zero (0).

### `StringLength` [in, out]

The size of the buffer pointed to by the *LinkName* parameter, in characters. If this
call fails and the error is **ERROR_MORE_DATA** (234), the value that is returned by this
parameter is the size that the buffer pointed to by *LinkName* must be to contain all
the data.

### `LinkName` [in, out]

A pointer to a buffer to store the first link name found for *lpFileName*.

### `hTransaction` [in, optional]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

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
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)