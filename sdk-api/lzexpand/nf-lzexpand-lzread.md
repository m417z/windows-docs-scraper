# LZRead function

## Description

Reads (at most) the specified number of bytes from a file and copies them into a buffer.

## Parameters

### `hFile` [in]

A handle to the file.

### `lpBuffer` [out]

A pointer to a buffer that receives the bytes read from the file. Ensure that this buffer is larger than *cbRead*.

### `cbRead` [in]

The count of bytes to be read.

## Return value

If the function succeeds, the return value specifies the number of bytes read.

If the function fails, the return value is an LZERROR_* code. These codes have values less than zero. Note that
**LZRead** calls neither [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor [SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a thread's last-error code.

The following is the list of error codes that
**LZRead** can return upon failure.

| Return code | Description |
| --- | --- |
| **LZERROR_BADINHANDLE** | The handle identifying the source file is not valid. The file cannot be read. |
| **LZERROR_BADOUTHANDLE** | The handle identifying the destination file is not valid. The file cannot be written. |
| **LZERROR_BADVALUE** | One of the input parameters is not valid. |
| **LZERROR_GLOBALLOC** | The maximum number of open compressed files has been exceeded or local memory cannot be allocated. |
| **LZERROR_GLOBLOCK** | The LZ file handle cannot be locked down. |
| **LZERROR_READ** | The source file format is not valid. |
| **LZERROR_WRITE** | There is insufficient space for the output file. |

There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle identifying the file must be retrieved by calling either the
[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit) or
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea) function.

If the file is compressed,
**LZRead** operates on an expanded image of the file and copies the bytes of data into the specified buffer.

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

[LZSeek](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzseek)