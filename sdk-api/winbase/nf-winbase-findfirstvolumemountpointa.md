# FindFirstVolumeMountPointA function

## Description

Retrieves the name of a mounted folder on the specified volume. **FindFirstVolumeMountPoint** is used to begin scanning the mounted folders on a
volume.

## Parameters

### `lpszRootPathName` [in]

A volume GUID path for the volume to scan for mounted folders. A trailing backslash is required.

### `lpszVolumeMountPoint` [out]

A pointer to a buffer that receives the name of the first mounted folder that is found.

### `cchBufferLength` [in]

The length of the buffer that receives the path to the mounted folder, in
**TCHAR**s.

## Return value

If the function succeeds, the return value is a search handle used in a subsequent call to the
[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa) and
[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose) functions.

If the function fails to find a mounted folder on the volume, the return value is the
**INVALID_HANDLE_VALUE** error code. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **FindFirstVolumeMountPoint** function
opens a mounted folder search handle and returns information about the first mounted folder that is found on the
specified volume. After the search handle is established, you can use the
[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa) function to search for
other mounted folders. When the search handle is no longer needed, close it with the
[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose) function.

The **FindFirstVolumeMountPoint**,
[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa), and
[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose) functions return
paths to mounted folders for a specified volume. They do not return drive letters or volume
**GUID** paths. For information about enumerating the volume
**GUID** paths for a volume, see
[Enumerating Volume GUID Paths](https://learn.microsoft.com/windows/desktop/FileIO/enumerating-unique-volume-names).

You should not assume any correlation between the order of the mounted folders that are returned by these
functions and the order of the mounted folders that are returned by other functions or tools.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB does not support volume management functions. CsvFS does not support adding mount point on a CSV volume.
ReFS does not index mount points.

> [!NOTE]
> The winbase.h header defines FindFirstVolumeMountPoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa)

[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)