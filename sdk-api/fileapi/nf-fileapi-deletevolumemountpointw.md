# DeleteVolumeMountPointW function

## Description

Deletes a drive letter or mounted folder.

## Parameters

### `lpszVolumeMountPoint` [in]

The drive letter or mounted folder to be deleted. A trailing backslash is required, for example,
"X:\" or "Y:\MountX\".

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Deleting a mounted folder does not cause the underlying directory to be deleted.

If the *lpszVolumeMountPoint* parameter is a directory that is not a mounted folder,
the function does nothing. The directory is not deleted.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB does not support volume management functions. For CsvFs, a new mount point will not be replicated to the other nodes on the cluster.

#### Examples

For an example, see
[Unmounting a Volume at a Mount Point](https://learn.microsoft.com/windows/desktop/FileIO/unmounting-a-volume-at-a-mount-point).

## See also

[GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)