# _CREATE_DISK structure

## Description

The CREATE_DISK structure is used with the [IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk) IOCTL to initialize a disk with an empty partition table. The partition table styles are master boot record (MBR) or GUID partition table (GPT).

## Members

### `PartitionStyle`

Takes a [PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85)) enumerated value that specifies the type of partition table to use when formatting the disk.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

Contains the signature used to initialize an MBR-style disk partition for the first time. This member is valid when **PartitionStyle** is PARTITION_STYLE_MBR. For more information, see [CREATE_DISK_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk_mbr).

### `DUMMYUNIONNAME.Gpt`

Contains data used to initialize a GPT-style disk partition for the first time. This member is valid when **PartitionStyle** is PARTITION_STYLE_GPT. For more information, see [CREATE_DISK_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk_gpt).

## See also

[CREATE_DISK_GPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk_gpt)

[CREATE_DISK_MBR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk_mbr)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk)

[PARTITION_STYLE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563773(v=vs.85))