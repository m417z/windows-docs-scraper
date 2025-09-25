# _DISK_GROW_PARTITION structure

## Description

The DISK_GROW_PARTITION structure is used in conjunction with the [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_grow_partition) request to enlarge a partition.

## Members

### `PartitionNumber`

Specifies a number identifying the partition to be enlarged.

### `BytesToGrow`

Indicates the number of bytes that the partition should be extended by. Note that this value is not the new size of the partition.

## See also

[IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_grow_partition)