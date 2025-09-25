# PARTITION_INFORMATION_MBR structure

## Description

Contains partition information specific to master boot record (MBR) disks.

## Members

### `PartitionType`

The type of partition. For a list of values, see
[Disk Partition Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-partition-types).

### `BootIndicator`

If the member is **TRUE**, the partition is a boot partition. When this structure is used with the
[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex) control code, the value of this parameter is ignored.

### `RecognizedPartition`

If this member is **TRUE**, the partition is of a recognized type. When this structure is used with the
[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex) control code, the value of this parameter is ignored.

### `HiddenSectors`

The number of hidden sectors to be allocated when the partition table is created.

### `PartitionId`

## See also

[File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)

[IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)

[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex)