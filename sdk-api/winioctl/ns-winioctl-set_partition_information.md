# SET_PARTITION_INFORMATION structure

## Description

Contains information used to set a disk partition's type.

**Note** **SET_PARTITION_INFORMATION** has been superseded by the
[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex) structure.

## Members

### `PartitionType`

The type of partition. For a list of values, see
[Disk Partition Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-partition-types).

## See also

[IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info)

[IOCTL_DISK_SET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex)