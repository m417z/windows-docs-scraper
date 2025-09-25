# _SET_PARTITION_INFORMATION_EX structure

## Description

**SET_PARTITION_INFORMATION_EX** is used with the IOCTL [IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info_ex) to set information for a specific partition.

## Members

### `PartitionStyle`

Takes a [PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) enumerated value that specifies the type of partition table that contains the partition.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

Contains the information for a Master Boot Record partition that is not held in common with a GUID Partition Table partition. This member is valid when **PartitionStyle** member is set to PARTITION_STYLE_MBR. For a definition of this structure, see [SET_PARTITION_INFORMATION_MBR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566198(v=vs.85)).

### `DUMMYUNIONNAME.Gpt`

Contains the information for a GUID Partition Table partition that is not held in common with a Master Boot Record partition. This member is valid when **PartitionStyle** member is set to PARTITION_STYLE_GPT. For a definition of this structure, see [SET_PARTITION_INFORMATION_GPT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566196(v=vs.85)).

## Remarks

In the case of GPT partitions, any value that can be retrieved from the partition can also be set. In the MBR case, only the partition signature can be set.

## See also

[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info_ex)

[SET_PARTITION_INFORMATION_GPT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566196(v=vs.85))

[SET_PARTITION_INFORMATION_MBR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566198(v=vs.85))