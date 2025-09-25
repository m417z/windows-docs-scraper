# LZCopy function

## Description

Copies a source file to a destination file. If the source file has been compressed by the Lempel-Ziv algorithm, this function creates a decompressed destination file. If the source file is not compressed, this function duplicates the original file.

## Parameters

### `hfSource` [in]

A handle to the source file.

### `hfDest` [in]

A handle to the destination file.

## Return value

If the function succeeds, the return value specifies the size, in bytes, of the destination file.

If the function fails, the return value is an LZERROR_* code. These codes have values less than zero. Note that
**LZCopy** calls neither
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor
[SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a thread's last-error code.

The following is a list of error codes that
**LZCopy** can return upon failure.

| Return code | Description |
| --- | --- |
| **LZERROR_BADINHANDLE** | The handle identifying the source file is not valid. The file cannot be read. |
| **LZERROR_BADOUTHANDLE** | The handle identifying the destination file is not valid. The file cannot be written. |
| **LZERROR_GLOBALLOC** | The maximum number of open compressed files has been exceeded or local memory cannot be allocated. |
| **LZERROR_GLOBLOCK** | The LZ file handle cannot be locked down. |
| **LZERROR_READ** | The source file format is not valid. |

There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handles identifying the source and destination files must be retrieved by calling the
[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit) or
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea) function.

If the function succeeds, the file identified by the *hfDest* parameter is always uncompressed.

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

[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit)

[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea)