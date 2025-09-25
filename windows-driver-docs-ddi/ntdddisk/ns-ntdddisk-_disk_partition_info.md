# _DISK_PARTITION_INFO structure

## Description

The **DISK_PARTITION_INFO** structure is used to report information about the disk's partition table.

## Members

### `SizeOfPartitionInfo`

Size of this structure in bytes. Set to **sizeof**(DISK_PARTITION_INFO).

### `PartitionStyle`

Takes a [PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) enumerated value that specifies the type of partition table the disk contains.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

If **PartitionStyle** == MBR

### `DUMMYUNIONNAME.Mbr.Signature`

Specifies the signature value, which uniquely identifies the disk. The **Mbr** member of the union is used to specify the disk signature data for a disk formatted with a Master Boot Record (MBR) format partition table. Any other value indicates that the partition is not a boot partition. This member is valid when **PartitionStyle** is **PARTITION_STYLE_MBR**.

### `DUMMYUNIONNAME.Mbr.CheckSum`

Specifies the checksum for the master boot record. The **Mbr** member of the union is used to specify the disk signature data for a disk formatted with a Master Boot Record (MBR) format partition table. This member is valid when **PartitionStyle** is **PARTITION_STYLE_MBR**.

### `DUMMYUNIONNAME.Gpt`

If **PartitionStyle** == GPT

### `DUMMYUNIONNAME.Gpt.DiskId`

Specifies the GUID that uniquely identifies the disk. The **Gpt** member of the union is used to specify the disk signature data for a disk that is formatted with a GUID Partition Table (GPT) format partition table. This member is valid when **PartitionStyle** is **PARTITION_STYLE_GPT**. The GUID data type is described on the [Using GUIDs in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-guids-in-drivers) reference page.

## See also

[DISK_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex)

[PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85))