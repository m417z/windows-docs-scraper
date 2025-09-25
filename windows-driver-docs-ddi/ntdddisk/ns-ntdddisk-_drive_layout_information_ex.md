# _DRIVE_LAYOUT_INFORMATION_EX structure

## Description

The DRIVE_LAYOUT_INFORMATION_EX structure is used to report information about the driver layout.

## Members

### `PartitionStyle`

Takes a [PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) enumerated value that specifies the type of partition table the disk contains.

### `PartitionCount`

Indicates the number of partitions detected on the disk.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

Indicates the drive layout information for a disk with a Master Boot Record. This member is valid when **PartitionStyle** is PARTITION_STYLE_MBR. See the definition of [DRIVE_LAYOUT_INFORMATION_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_mbr) for more information.

### `DUMMYUNIONNAME.Gpt`

Indicates the drive layout information for a disk with a GUID Partition Table. This member is valid when **PartitionStyle** is PARTITION_STYLE_GPT. See definition of [DRIVE_LAYOUT_INFORMATION_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_gpt) for more information.

### `PartitionEntry`

Contains a variable-length array of [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex) structures, one for each partition on the drive.

## Remarks

This structure is used for both reading and writing disk partition information. It is used with [IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex) and [IoWritePartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontableex) and replaces the obsolete structure DRIVE_LAYOUT_INFORMATION that was used with **IoReadPartitionTable** and **IoWritePartitionTable**. The principal difference is that the new structures and routines support both Master Boot Record (MBR) partitions and GUID Partition Table (GPT) partitions, whereas the older routines and structures are only used with MBR partitions.

## See also

[DRIVE_LAYOUT_INFORMATION_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_gpt)

[DRIVE_LAYOUT_INFORMATION_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_mbr)

[IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex)

[IoWritePartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontableex)

[PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85))