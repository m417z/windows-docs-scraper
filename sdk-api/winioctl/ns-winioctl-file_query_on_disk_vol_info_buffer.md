# FILE_QUERY_ON_DISK_VOL_INFO_BUFFER structure

## Description

Receives the volume information from a call to [FSCTL_QUERY_ON_DISK_VOLUME_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_on_disk_volume_info).

## Members

### `DirectoryCount`

The number of directories on the specified disk. This member is -1 if the number is unknown.

For UDF file systems with a virtual allocation table, this information is available only if the UDF revision is greater than 1.50.

### `FileCount`

The number of files on the specified disk. Returns -1 if the number is unknown.

For UDF file systems with a virtual allocation table, this information is available only if the UDF revision is greater than 1.50.

### `FsFormatMajVersion`

The major version number of the file system. Returns -1 if the number is unknown or not applicable. On UDF 1.02 file systems, 1 is returned.

### `FsFormatMinVersion`

The minor version number of the file system. Returns -1 if the number is unknown or not applicable. On UDF 1.02 file systems, 02 is returned.

### `FsFormatName`

Always returns UDF.

### `FormatTime`

The time the media was formatted.

### `LastUpdateTime`

The time the media was last updated.

### `CopyrightInfo`

Any copyright information associated with the volume.

### `AbstractInfo`

Any abstract information written on the media.

### `FormattingImplementationInfo`

Implementation-specific information; in some cases, it is the operating system version that the media was formatted by.

### `LastModifyingImplementationInfo`

The last implementation that modified the disk. This information is implementation specific; in some cases, it is the operating system version that the media was last modified by.

## See also

[FSCTL_QUERY_ON_DISK_VOLUME_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_on_disk_volume_info)