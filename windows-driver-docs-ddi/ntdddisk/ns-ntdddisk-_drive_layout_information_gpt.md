# _DRIVE_LAYOUT_INFORMATION_GPT structure

## Description

The DRIVE_LAYOUT_INFORMATION_GPT structure reports the drive signature for a GUID Partition Table partition.

## Members

### `DiskId`

Contains a GUID that uniquely identifies the drive. The GUID data type is described on the [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) reference page.

### `StartingUsableOffset`

Contains an offset in bytes to the location immediately following the primary partition table. This offset begins the region on the drive where partitions reside, but partition one is not necessarily located precisely at this offset.

### `UsableLength`

Indicates the total usable space in bytes available on the drive.

### `MaxPartitionCount`

Indicates the maximum number of partitions allowed on the drive.

## Remarks

This structure contains the drive layout information that is specific to a drive with a GUID Partition Table partition. It is encapsulated within the [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex) structure. For further information see Intel's *Extensible Firmware Interface* specification.

## See also

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex)

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)