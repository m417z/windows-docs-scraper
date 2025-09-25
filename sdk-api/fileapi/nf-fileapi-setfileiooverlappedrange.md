# SetFileIoOverlappedRange function

## Description

 Associates a virtual address range with the specified file handle. This indicates that the
kernel should optimize any further asynchronous I/O requests with overlapped structures inside this range. The
overlapped range is locked in memory, and then unlocked when the file is closed. After a range is associated with
a file handle, it cannot be disassociated.

## Parameters

### `FileHandle` [in]

A handle to the file.

This file handle must be opened with **FILE_READ_ATTRIBUTES** access rights.

### `OverlappedRangeStart` [in]

The starting address for the range.

### `Length` [in]

The length of the range, in bytes.

## Return value

Returns nonzero if successful or zero otherwise.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetFileIoOverlappedRange** can be used to
improve performance in an application that issues a high number of asynchronous unbuffered I/O and uses a defined
range of overlapped structures. Because this range of structures is locked in memory, the kernel can avoid
acquiring certain locks when updating the overlapped structures with the results of the I/O request.

**SetFileIoOverlappedRange** requires the
caller to have the [SeLockMemoryPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)
access privilege.

This function has no effect on buffered and synchronous I/O.

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