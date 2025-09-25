# GetLogicalDriveStringsW function

## Description

Fills a buffer with strings that specify valid drives in the system.

## Parameters

### `nBufferLength` [in]

The maximum size of the buffer pointed to by *lpBuffer*, in
**TCHARs**. This size does not include the terminating null character. If this
parameter is zero, *lpBuffer* is not used.

### `lpBuffer` [out]

A pointer to a buffer that receives a series of null-terminated strings, one for each valid drive in the
system, plus with an additional null character. Each string is a device name.

## Return value

If the function succeeds, the return value is the length, in characters, of the strings copied to the buffer,
not including the terminating null character. Note that an ANSI-ASCII null character uses one byte, but a
Unicode (UTF-16) null character uses two bytes.

If the buffer is not large enough, the return value is greater than *nBufferLength*.
It is the size of the buffer required to hold the drive strings.

If the function fails, the return value is zero. To get extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Each string in the buffer may be used wherever a root directory is required, such as for the
[GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea) and
[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) functions.

This function returns a concatenation of the drives in the Global and Local MS-DOS Device namespaces. If a
drive exists in both namespaces, this function will return the entry in the Local MS-DOS Device namespace. For
more information, see
[Defining an MS DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

#### Examples

For an example, see
[Obtaining a File Name From a File Handle](https://learn.microsoft.com/windows/desktop/Memory/obtaining-a-file-name-from-a-file-handle).

## See also

[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea)

[GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea)

[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)