# GetFileType function

## Description

Retrieves the file type of the specified file.

## Parameters

### `hFile` [in]

A handle to the file.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **FILE_TYPE_CHAR**<br><br>0x0002 | The specified file is a character file, typically an LPT device or a console. |
| **FILE_TYPE_DISK**<br><br>0x0001 | The specified file is a disk file. |
| **FILE_TYPE_PIPE**<br><br>0x0003 | The specified file is a socket, a named pipe, or an anonymous pipe. |
| **FILE_TYPE_REMOTE**<br><br>0x8000 | Unused. |
| **FILE_TYPE_UNKNOWN**<br><br>0x0000 | Either the type of the specified file is unknown, or the function failed. |

You can distinguish between a "valid" return of **FILE_TYPE_UNKNOWN** and its return due to a calling error (for example, passing an invalid handle to
**GetFileType**) by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function worked properly and **FILE_TYPE_UNKNOWN** was returned, a call to **GetLastError** will return **NO_ERROR**.

If the function returned **FILE_TYPE_UNKNOWN** due to an error in calling
**GetFileType**,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return the error code.

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

[GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize)

[GetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletime)