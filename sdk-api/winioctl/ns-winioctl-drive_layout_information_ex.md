# DRIVE_LAYOUT_INFORMATION_EX structure

## Description

Contains extended information about a drive's partitions.

## Members

### `PartitionStyle`

The style of the partitions on the drive enumerated by the [**PARTITION_STYLE**](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-partition_style) enumeration.

| Style | Value | Meaning |
| --- | --- | --- |
| **PARTITION_STYLE_MBR** | 0 | Master boot record (MBR) format.|
| **PARTITION_STYLE_GPT** | 1 | GUID Partition Table (GPT) format. |
| **PARTITION_STYLE_RAW** | 2 | Partition not formatted in either of the recognized formats—MBR or GPT. |

### `PartitionCount`

The number of partitions on the drive. On hard disks with the MBR layout, this value will always be a multiple of 4. Any partitions that are actually unused will have a partition type of **PARTITION_ENTRY_UNUSED** (0) set in the **PartitionType** member of the [**PARTITION_INFORMATION_MBR**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information_mbr) structure of the **Mbr** member of the [**PARTITION_INFORMATION_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information_ex) structure of the **PartitionEntry** member of this structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

A [**DRIVE_LAYOUT_INFORMATION_MBR**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_mbr) structure containing information about the master boot record type partitioning on the drive.

### `DUMMYUNIONNAME.Gpt`

A [**DRIVE_LAYOUT_INFORMATION_GPT**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_gpt) structure containing information about the GUID disk partition type partitioning on the drive.

### `PartitionEntry`

A variable-sized array of [**PARTITION_INFORMATION_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information_ex) structures, one structure for each partition on the drive.

## See also

[DRIVE_LAYOUT_INFORMATION_GPT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_gpt), [DRIVE_LAYOUT_INFORMATION_MBR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_mbr), [IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex), [IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout), [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information_ex), [PARTITION_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information)