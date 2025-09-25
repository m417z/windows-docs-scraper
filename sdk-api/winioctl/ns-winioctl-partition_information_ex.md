# PARTITION_INFORMATION_EX structure

## Description

Contains partition information for standard *AT-style* master boot record (MBR) and Extensible Firmware Interface (EFI) disks.

## Members

### `PartitionStyle`

The format of the partition. For a list of values, see
[PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-partition_style).

### `StartingOffset`

The starting offset of the partition.

### `PartitionLength`

The size of the partition, in bytes.

### `PartitionNumber`

The number of the partition (1-based).

### `RewritePartition`

If this member is **TRUE**, the partition is rewritable. The value of this parameter should be set to **TRUE**.

### `IsServicePartition`

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

A
[PARTITION_INFORMATION_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_mbr) structure that specifies partition information specific to master boot record (MBR) disks. The MBR partition format is the standard *AT-style* format.

### `DUMMYUNIONNAME.Gpt`

A
[PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_gpt) structure that specifies partition information specific to GUID partition table (GPT) disks. The GPT format corresponds to the EFI partition format.

## Remarks

If the partition is on a disk formatted as type master boot record (MBR), partition size totals are limited. For more information, see the Remarks section of [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout).

## See also

[File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)

[IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)

[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex)

[PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_gpt)

[PARTITION_INFORMATION_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_mbr)

[PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-partition_style)