# GetFileInformationByHandle function

## Description

Retrieves file information for the specified file.

For a more advanced version of this function, see
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

To set file information using a file handle, see
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle).

## Parameters

### `hFile` [in]

A handle to the file that contains the information to be retrieved.

This handle should not be a pipe handle.

### `lpFileInformation` [out]

A pointer to a
[BY_HANDLE_FILE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-by_handle_file_information) structure that
receives the file information.

## Return value

If the function succeeds, the return value is nonzero and file information data is contained in the buffer
pointed to by the *lpFileInformation* parameter.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Depending on the underlying network features of the operating system and the type of server connected to, the
**GetFileInformationByHandle** function may fail,
return partial information, or full information for the given file.

You can compare the **VolumeSerialNumber** and **FileIndex**
members returned in the
[BY_HANDLE_FILE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-by_handle_file_information) structure to
determine if two paths map to the same target; for example, you can compare two file paths and determine if they
map to the same directory.

IIn Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

### Transacted Operations

If there is a transaction bound to the thread at the time of the call, then the function returns the
compressed file size of the isolated file view. For more information, see
[About Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/about-transactional-ntfs).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)