# FlushFileBuffers function

## Description

Flushes the buffers of a specified file and causes all buffered data to be written to a file.

## Parameters

### `hFile` [in]

A handle to the open file.

The file handle must have the **GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

If *hFile* is a handle to a communications device, the function only flushes the transmit buffer.

If *hFile* is a handle to the server end of a named pipe, the function does not return until the client has read all buffered data from the pipe.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The function fails if *hFile* is a handle to the console output. That is because the console output is not buffered. The function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_HANDLE**.

## Remarks

Typically the
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) and
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) functions write data to an internal buffer that the operating system writes to a disk or communication pipe on a regular basis. The
**FlushFileBuffers** function writes all the buffered information for a specified file to the device or pipe.

Due to disk caching interactions within the system, the
**FlushFileBuffers** function can be inefficient when used after every write to a disk drive device when many writes are being performed separately. If an application is performing multiple writes to disk and also needs to ensure critical data is
written to persistent media, the application should use unbuffered I/O instead of frequently calling **FlushFileBuffers**. To open a file for unbuffered I/O, call the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with the **FILE_FLAG_NO_BUFFERING** and **FILE_FLAG_WRITE_THROUGH** flags. This prevents the file contents from being cached and flushes the metadata to disk with each write. For more information, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

To flush all open files on a volume, call **FlushFileBuffers** with a handle to the volume. The caller must have administrative privileges. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

When opening a volume with [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea), the *lpFileName* string should be the following form: \\.\*x*: or \\?\Volume{*GUID*}. Do not use a trailing backslash in the volume name, because that indicates the root directory of a drive.

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
[Multithreaded Pipe Server](https://learn.microsoft.com/windows/desktop/ipc/multithreaded-pipe-server).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)