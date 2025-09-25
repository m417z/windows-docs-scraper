# FindNextVolumeMountPointW function

## Description

Continues a mounted folder search started by a call to the
[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa)
function. **FindNextVolumeMountPoint** finds one mounted
folder per call.

## Parameters

### `hFindVolumeMountPoint` [in]

A mounted folder search handle returned by a previous call to the
[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa) function.

### `lpszVolumeMountPoint` [out]

A pointer to a buffer that receives the name of the mounted folder that is found.

### `cchBufferLength` [in]

The length of the buffer that receives the mounted folder name, in
**TCHARs**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If no more mounted folders can be found,
the **GetLastError** function returns the
**ERROR_NO_MORE_FILES** error code. In that case, close the search with the
[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose) function.

## Remarks

After the search handle is established by calling
[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa), you can
use the **FindNextVolumeMountPoint** function to
search for other mounted folders.

The [FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa),
**FindNextVolumeMountPoint**, and
[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose) functions return
paths to mounted folders for a specified volume. They do not return drive letters or volume GUID paths. For
information about enumerating the volume **GUID** paths for a volume, see
[Enumerating Volume GUID Paths](https://learn.microsoft.com/windows/desktop/FileIO/enumerating-unique-volume-names).

You should not assume any correlation between the order of the mounted folders that are returned with these
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
> The winbase.h header defines FindNextVolumeMountPoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa)

[FindVolumeMountPointClose](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findvolumemountpointclose)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)