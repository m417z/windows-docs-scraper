# GetVolumePathNamesForVolumeNameA function

## Description

Retrieves a list of drive letters and mounted folder paths for the specified volume.

## Parameters

### `lpszVolumeName` [in]

A volume **GUID** path for the volume. A volume **GUID**
path is of the form
"\\?\Volume{*xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx*}\".

### `lpszVolumePathNames` [out]

A pointer to a buffer that receives the list of drive letters and mounted folder paths. The list is an
array of null-terminated strings terminated by an additional **NULL** character. If the
buffer is not large enough to hold the complete list, the buffer holds as much of the list as possible.

### `cchBufferLength` [in]

The length of the *lpszVolumePathNames* buffer, in
**TCHARs**, including all **NULL** characters.

### `lpcchReturnLength` [out]

If the call is successful, this parameter is the number of **TCHARs** copied to
the *lpszVolumePathNames* buffer. Otherwise, this parameter is the size of the buffer
required to hold the complete list, in **TCHARs**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the buffer is not large enough to
hold the complete list, the error code is **ERROR_MORE_DATA** and the
*lpcchReturnLength* parameter receives the required buffer size.

## Remarks

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
[Displaying Volume Paths](https://learn.microsoft.com/windows/desktop/FileIO/displaying-volume-paths).

## See also

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)