# LZInit function

## Description

Allocates memory for the internal data structures required to decompress files, and then creates and initializes them.

## Parameters

### `hfSource` [in]

A handle to the file.

## Return value

If the function succeeds, the return value is a new LZ file handle.

If the function fails, the return value is an LZERROR_* code. These codes have values less than zero. Note that
**LZInit** calls neither
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor
[SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a thread's last-error code.

The following is the list of the error codes that
**LZInit** can return upon failure.

| Return code | Description |
| --- | --- |
| **LZERROR_BADINHANDLE** | The handle identifying the source file is not valid. The file cannot be read. |
| **LZERROR_GLOBALLOC** | The maximum number of open compressed files has been exceeded or local memory cannot be allocated. |
| **LZERROR_GLOBLOCK** | The LZ file handle cannot be locked down. |
| **LZERROR_UNKNOWNALG** | The file is compressed with an unrecognized compression algorithm. |

There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A maximum of 16 compressed files can be open at any given time. Similarly, a maximum of 16 uncompressed files can be open at any given time. An application should be careful to close the handle returned by
**LZInit** when it is done using the file; otherwise, the application can inadvertently hit the 16-file limit.

The handle this function returns is compatible only with the functions in Lz32.dll; it should not be used for other file operations.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

CsvFs will do redirected IO for compressed files.

## See also

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)