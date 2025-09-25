# SetVolumeMountPointA function

## Description

Associates a volume with a drive letter or a directory on another volume.

## Parameters

### `lpszVolumeMountPoint` [in]

The user-mode path to be associated with the volume. This may be a drive letter (for example, "X:\\") or a directory
on another volume (for example, "Y:\\MountX\\"). The string must end with a trailing backslash ('\\').

### `lpszVolumeName` [in]

A volume **GUID** path for the volume. This string must be of the form
"\\\\?\\Volume{*GUID*}\\" where *GUID* is a **GUID** that identifies
the volume. The "\\\\?\\" turns off path parsing and is ignored as part of the path, as discussed in
[Naming a Volume](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-volume).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the *lpszVolumeMountPoint* parameter contains a path to a mounted folder, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_DIR_NOT_EMPTY**, even if the directory is empty.

## Remarks

When this function is used to associate a volume with a directory on another volume, the associated directory is called a *mounted folder*.

It is an error to associate a volume with a directory that has any files or subdirectories in it. This
error occurs for system and hidden directories as well as other directories, and it occurs for system and hidden
files.

When mounted folders are created on a volume on a clustered disk, they may be deleted unexpectedly under certain
circumstances. For information on how to create and configure mounted folders to ensure that this does not happen,
see [Cluster Disk and Drive Connection Problems](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757627(v=ws.10)).

IIn Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB does not support volume management functions. For CsvFS a new mount point will not be replicated to the other nodes on the cluster.

#### Examples

For an example, see
[Creating a Mounted Folder](https://learn.microsoft.com/windows/desktop/FileIO/mounting-a-volume-at-a-mount-point).

> [!NOTE]
> The winbase.h header defines SetVolumeMountPoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletevolumemountpointw)

[GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)