# _PARTITION_INFORMATION_GPT structure

## Description

PARTITION_INFORMATION_GPT contains information for a GUID Partition Table partition that is not held in common with a Master Boot Record partition.

## Members

### `PartitionType`

Specifies a GUID that uniquely identifies the partition type. The GUID data type is described on the [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) reference page.

### `PartitionId`

Specifies a GUID that uniquely identifies the partition. The GUID data type is described on the [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) reference page.

### `Attributes`

Specifies the partition entry attributes used for diagnostics, recovery tools, and other firmware essential to the operation of the device. See Intel's *Extensible Firmware Interface* specification for further information.

### `Name`

Specifies the partition name in Unicode.

## See also

[IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex)