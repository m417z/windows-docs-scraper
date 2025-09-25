# GetFileSizeEx function

## Description

Retrieves the size of the specified file.

## Parameters

### `hFile` [in]

A handle to the file. The handle must have been created with the
**FILE_READ_ATTRIBUTES** access right or equivalent, or the caller must have sufficient permission on the directory that contains the file.
For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `lpFileSize` [out]

A pointer to a [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that
receives the file size, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Transacted Operations:** If there is a transaction bound to the file handle, then the function returns information for the isolated
file view.

**Windows Store apps:** **GetFileSizeEx** is not supported. Use
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

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

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)