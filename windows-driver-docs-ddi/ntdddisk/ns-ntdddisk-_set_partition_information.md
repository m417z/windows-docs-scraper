# _SET_PARTITION_INFORMATION structure

## Description

SET_PARTITION_INFORMATION is used with IOCTL_DISK_SET_PARTITION_INFO to change the partition type of a specified Master Boot Record (MBR) disk partition.

## Members

### `PartitionType`

Indicates the partition type. IOCTL_DISK_SET_PARTITION_INFO uses this value to set the partition type. See [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information) for a list of system-defined GPT partition types.

## Remarks

The single byte unsigned value, *PartitionType*, contained in this structure defines a traditional AT Master Boot Record style of partition and cannot be used to define an Extensible Firmware Interface partition (also known as a GUID Partition Table partition). GPT partitions use a GUID to indicate the partition type.

## See also

[IOCTL_DISK_SET_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info)

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[SET_PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information_ex)

[SET_PARTITION_INFORMATION_GPT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566196(v=vs.85))

[SET_PARTITION_INFORMATION_MBR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566198(v=vs.85))