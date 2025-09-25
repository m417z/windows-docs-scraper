# _DRIVE_LAYOUT_INFORMATION_MBR structure

## Description

The DRIVE_LAYOUT_INFORMATION_MBR structure reports the drive signature for a Master Boot Record partition.

## Members

### `Signature`

Specifies the disk signature value, which uniquely identifies the disk.

### `CheckSum`

## Remarks

This structure contains the drive layout information that is specific to a drive with a Master Boot Record partition. It is contained within the [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex) structure.

## See also

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex)

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)