# DRIVE_LAYOUT_INFORMATION structure

## Description

Contains information about the partitions of a drive.

> [!NOTE]
> **DRIVE_LAYOUT_INFORMATION** is superseded [**DRIVE_LAYOUT_INFORMATION_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_ex) structure.

## Members

### `PartitionCount`

The number of partitions on a drive.

On disks with the MBR layout, this value is always a multiple of 4. Any partitions that are unused have a partition type of **PARTITION_ENTRY_UNUSED** (0).

### `Signature`

The drive signature value.

### `PartitionEntry`

A variable-sized array of [**PARTITION_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information) structures, one structure for each partition on a drive.

## See also

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_ex), [IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout), [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout)