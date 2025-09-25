# DRIVE_LAYOUT_INFORMATION_GPT structure

## Description

Contains information about a drive's GUID partition table (GPT) partitions.

## Members

### `DiskId`

The **GUID** of the disk.

### `StartingUsableOffset`

The starting byte offset of the first usable block.

### `UsableLength`

The size of the usable blocks on the disk, in bytes.

### `MaxPartitionCount`

The maximum number of partitions that can be defined in the usable block.

## See also

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-drive_layout_information_ex)

[DRIVE_LAYOUT_INFORMATION_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-drive_layout_information_mbr)

[IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex)

[IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout)