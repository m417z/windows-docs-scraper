# DEVICE_SEEK_PENALTY_DESCRIPTOR structure

## Description

Used in conjunction with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request to
retrieve the seek penalty descriptor data for a device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `IncursSeekPenalty`

Specifies whether the device incurs a seek penalty.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)