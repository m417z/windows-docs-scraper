# GetVolumeNameForVolumeMountPointW function

## Description

Retrieves a volume **GUID** path for the volume that is associated with the specified volume mount point (
drive letter, volume **GUID** path, or mounted folder).

## Parameters

### `lpszVolumeMountPoint` [in]

A pointer to a string that contains the path of a mounted folder (for example, "Y:\MountX\\") or a drive letter (for example, "X:\\"). The string must end with a trailing backslash ('\\').

### `lpszVolumeName` [out]

A pointer to a string that receives the volume **GUID** path. This path is of the form "\\\\?\Volume{*GUID*}\\" where *GUID* is a **GUID** that identifies the volume. If there is more than one volume **GUID** path for the volume, only the first one in the mount manager's cache is returned.

### `cchBufferLength` [in]

The length of the output buffer, in **TCHARs**. A reasonable size for the buffer to accommodate the largest possible volume **GUID** path is 50 characters.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use
**GetVolumeNameForVolumeMountPoint** to obtain a volume **GUID** path for use with functions such as [SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa) and [FindFirstVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstvolumemountpointa) that require a volume **GUID** path as an input parameter. For more information about volume **GUID** paths, see
[Naming A Volume](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-volume).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | No |

SMB does not support volume management functions.

Mount points aren't supported by ReFS volumes.

## See also

[DeleteVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletevolumemountpointw)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)