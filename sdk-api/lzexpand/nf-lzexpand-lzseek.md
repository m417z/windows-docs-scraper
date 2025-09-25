# LZSeek function

## Description

Moves a file pointer the specified number of bytes from a starting position.

## Parameters

### `hFile` [in]

A handle to the file.

### `lOffset` [in]

The number of bytes by which to move the file pointer.

### `iOrigin` [in]

The starting position of the pointer. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Moves the file pointer *lOffset* bytes from the beginning of the file. |
| 1 | Moves the file pointer *lOffset* bytes from the current position. |
| 2 | Moves the file pointer *lOffset* bytes from the end of the file. |

## Return value

If the function succeeds, the return value specifies the offset from the beginning of the file to the new pointer position.

If the function fails, the return value is an LZERROR_* code. These codes have values less than zero. Note that
**LZSeek** calls neither [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor [SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a thread's last-error code.

The following is the list of error codes that
**LZSeek** can return upon failure.

| Return code | Description |
| --- | --- |
| **LZERROR_BADINHANDLE** | The handle identifying the source file is not valid. The file cannot be read. |
| **LZERROR_BADVALUE** | One of the parameters is outside the range of acceptable values. |
| **LZERROR_GLOBLOCK** | The LZ file handle cannot be locked down. |

There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle identified by the *hFile* parameter must be retrieved by calling either the
[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit) or
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea) function.

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