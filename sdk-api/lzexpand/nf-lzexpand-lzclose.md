# LZClose function

## Description

Closes a file that was opened by using the
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea) function.

## Parameters

### `hFile` [in]

A handle to the file to be closed.

## Remarks

The handle identifying the file must be retrieved by calling the
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea) function. If the handle is retrieved by calling the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or
[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function, an error occurs.

If the file has been compressed by the Lempel-Ziv algorithm and opened by using
[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea),
**LZClose** frees any global heap space that was allocated to expand the file.

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

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[LZOpenFile](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzopenfilea)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)