# FindClose function

## Description

Closes a file search handle opened by the
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea),
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa),
[FindFirstFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilenamew),
[FindFirstFileNameTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfilenametransactedw),
[FindFirstFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfiletransacteda),
[FindFirstStreamTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirststreamtransactedw), or
[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) functions.

## Parameters

### `hFindFile` [in, out]

The file search handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the **FindClose** function is called, the handle
specified by the *hFindFile* parameter cannot be used in subsequent calls to the
[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea),
[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew),
[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw), or
**FindClose** functions.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Listing the Files in a Directory](https://learn.microsoft.com/windows/desktop/FileIO/listing-the-files-in-a-directory).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa)

[FindFirstFileNameTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfilenametransactedw)

[FindFirstFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilenamew)

[FindFirstFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfiletransacteda)

[FindFirstStreamTransactedW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirststreamtransactedw)

[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[FindNextFileNameW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilenamew)

[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw)