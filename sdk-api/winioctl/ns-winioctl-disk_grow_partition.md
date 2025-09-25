# DISK_GROW_PARTITION structure

## Description

Contains information used to increase the size of a partition.This structure is used by the [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_grow_partition) control code.

## Members

### `PartitionNumber`

The identifier of the partition to be enlarged.

### `BytesToGrow`

The number of bytes by which the partition is to be enlarged (positive value) or reduced (negative value). Note that this value is not the new size of the partition.

## See also

[IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_grow_partition)

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)