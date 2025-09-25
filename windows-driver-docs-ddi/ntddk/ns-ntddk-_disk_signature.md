# _DISK_SIGNATURE structure

## Description

DISK_SIGNATURE contains the disk signature information for a disk's partition table.

## Members

### `PartitionStyle`

Specifies the type of partition. See [PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) for a description of the possible values.

### `Mbr`

### `Mbr.Signature`

Specifies the signature value, which uniquely identifies the disk. The **Mbr** member of the union is used to specify the disk signature data for a disk formatted with a Master Boot Record (MBR) format partition table. This member is valid when **PartitionStyle** is PARTITION_STYLE_MBR.

### `Mbr.CheckSum`

Specifies the checksum for the master boot record. The **Mbr** member of the union is used to specify the disk signature data for a disk formatted with a Master Boot Record (MBR) format partition table. This member is valid when **PartitionStyle** is PARTITION_STYLE_MBR.

### `Gpt`

### `Gpt.DiskId`

Specifies the GUID that uniquely identifies the disk. The **Gpt** member of the union is used to specify the disk signature data for a disk that is formatted with a GUID Partition Table (GPT) format partition table. The GUID data type is described on the [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) reference page. This member is valid when **PartitionStyle** is PARTITION_STYLE_GPT.

## See also

[IoReadDiskSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreaddisksignature)