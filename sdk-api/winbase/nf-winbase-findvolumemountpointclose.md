# FindVolumeMountPointClose function

## Description

Closes the specified mounted folder search handle. The
[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa) and
[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa) functions use this search handle to locate mounted folders on a specified volume.

## Parameters

### `hFindVolumeMountPoint` [in]

The mounted folder search handle to be closed. This handle must have been previously opened by the
[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the
**FindVolumeMountPointClose** function is called, the handle *hFindVolumeMountPoint* cannot be used in subsequent calls to either
[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa) or
**FindVolumeMountPointClose**.

The [FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa), [FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa), and **FindVolumeMountPointClose** functions return paths to mounted folders for a specified volume. They do not return drive letters or volume GUID paths. For information about enumerating the volume GUID paths for a volume, see [Enumerating Volume GUID Paths](https://learn.microsoft.com/windows/desktop/FileIO/enumerating-unique-volume-names).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions. CsvFS does not support adding mount point on a CSV volume.

## See also

[FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa)

[FindNextVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findnextvolumemountpointa)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume
Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)