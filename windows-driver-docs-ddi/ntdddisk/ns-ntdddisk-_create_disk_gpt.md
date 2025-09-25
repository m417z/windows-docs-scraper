# _CREATE_DISK_GPT structure

## Description

The CREATE_DISK_GPT structure is used with the IOCTL [IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk) to initialize a disk with an empty GPT partition table.

## Members

### `DiskId`

Specifies the GUID that uniquely identifies the disk.

### `MaxPartitionCount`

Specifies the maximum number of partitions allowed on the disk.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk)