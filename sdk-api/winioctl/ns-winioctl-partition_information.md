# PARTITION_INFORMATION structure

## Description

Contains information about a disk partition.

**Note** **PARTITION_INFORMATION** has been superseded by the
[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex) structure.

## Members

### `StartingOffset`

The starting offset of the partition.

### `PartitionLength`

The length of the partition, in bytes.

### `HiddenSectors`

The number of hidden sectors in the partition.

### `PartitionNumber`

The number of the partition (1-based).

### `PartitionType`

The type of partition. For a list of values, see
[Disk Partition Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-partition-types).

### `BootIndicator`

If this member is **TRUE**, the partition is bootable.

### `RecognizedPartition`

If this member is **TRUE**, the partition is of a recognized type.

### `RewritePartition`

If this member is **TRUE**, the partition information has changed. When you change a partition (with
[IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout)), the system uses this member to determine which partitions have changed and need their information rewritten.

## Remarks

If the partition is on a disk formatted as type master boot record (MBR), partition size totals are limited. For more information, see the Remarks section of [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout).

## See also

[File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)

[IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout)

[IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info)

[IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout)

[IOCTL_DISK_SET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex)

[PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-partition_style)