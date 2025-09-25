# SetEndOfFile function

## Description

Sets the physical file size for the specified file to the current position of the file pointer.

The physical file size is also referred to as the end of the file. The **SetEndOfFile** function can be used to truncate or extend a file. To set the logical end of a file, use the [SetFileValidData](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilevaliddata) function.

## Parameters

### `hFile` [in]

A handle to the file to be extended or truncated.

 The file handle must be created with the **GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetEndOfFile** function can be used to truncate or extend a file. If the file is extended, the contents of the file between the old end of the file and the new end of the file are not defined.

Each file stream has the following:

* File size: the size of the data in a file, to the byte.
* Allocation size: the size of the space that is allocated for a file on a disk, which is always an even multiple of the cluster size.
* Valid data length: the length of the data in a file that is actually written, to the byte. This value is always less than or equal to the file size.

The **SetEndOfFile** function sets the file size. Use [SetFileValidData](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilevaliddata) to set the valid data length.

If
[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) is called to create a file mapping object for *hFile*, [UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) must be called first to unmap all views and call
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to close the file mapping object before you can call
**SetEndOfFile**.

### Transacted Operations

If there is a transaction bound to the handle, then the change in the end-of-file position is transacted.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)

[SetFileValidData](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilevaliddata)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)