# _PARTITION_INFORMATION_MBR structure

## Description

PARTITION_INFORMATION_MBR contains information for a Master Boot Record partition that is not held in common with a GUID Partition Table partition.

## Members

### `PartitionType`

Specifies the partition type. See [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information) for a list of system-defined partition types.

### `BootIndicator`

Indicates, when **TRUE**, that the partition is bootable. When **FALSE**, the partition is not bootable.

### `RecognizedPartition`

Indicates, when **TRUE**, that this is a partition with a recognized partition type. When **FALSE** this is a not a partition with a recognized partition.

### `HiddenSectors`

Contains the number of hidden sectors in the partition.

### `PartitionId`

## See also

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex)

[PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_gpt)