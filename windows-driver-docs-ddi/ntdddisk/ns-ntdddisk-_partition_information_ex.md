# PARTITION_INFORMATION_EX structure

## Description

PARTITION_INFORMATION_EX is the extended version of the [**PARTITION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information) structure. It holds information both for partitions with a Master Boot Record and for partitions with a GUID Partition Table.

## Members

### `PartitionStyle`

Takes a [**PARTITION_STYLE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) enumerated value that specifies the type of partition table that contains the partition.

### `StartingOffset`

Specifies the offset in bytes on drive where the partition begins.

### `PartitionLength`

Specifies the length in bytes of the partition.

### `PartitionNumber`

Specifies the number of the partition.

### `RewritePartition`

Indicates, when **TRUE**, that the partition information has changed. When **FALSE**, the information has not changed. This member has a value of **TRUE** when the partition has changed as a result of an [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout) IOCTL. This informs the system that the partition information needs to be rewritten.

### `IsServicePartition`

When **TRUE**, indicates that the partition is service.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

Contains a structure of type [PARTITION_INFORMATION_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_mbr) containing information specific to a partition with a **PartitionStyle** member of PARTITION_STYLE_MBR.

### `DUMMYUNIONNAME.Gpt`

Contains a structure of type [PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_gpt) containing information specific to a partition with a **PartitionStyle** member of PARTITION_STYLE_GPT.

## Remarks

This is the extended version of the partition information structure, PARTITION_INFORMATION. [IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex) and [IoWritePartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontableex) operate on an array of PARTITON_INFORMATION_EX structures contained within the extended drive layout structure, [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex). **PARTITION_INFORMATION_EX** replaces the structure **PARTITION_INFORMATION** that was used with [IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable) and [IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable). The principle difference is that the new structures and routines support both Master Boot Record (MBR) partitions and GUID Partition Table (GPT) partitions, whereas the older routines and structures are only used with MBR partitions.

## See also

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)

[PARTITION_INFORMATION_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_gpt)

[PARTITION_INFORMATION_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_mbr)