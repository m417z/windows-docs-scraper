# PARTITION_STYLE enumeration

## Description

Represents the format of a partition.

## Constants

### `PARTITION_STYLE_MBR`

Master boot record (MBR) format. This corresponds to standard *AT-style* MBR partitions.

### `PARTITION_STYLE_GPT`

GUID Partition Table (GPT) format.

### `PARTITION_STYLE_RAW`

Partition not formatted in either of the recognized formats—MBR or GPT.

## See also

* [File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)
* [IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)
* [IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex)
* [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information_ex)