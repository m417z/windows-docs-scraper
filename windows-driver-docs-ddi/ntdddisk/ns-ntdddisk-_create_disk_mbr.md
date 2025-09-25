# _CREATE_DISK_MBR structure

## Description

The CREATE_DISK_MBR structure is used with the IOCTL [IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk) to initialize a disk with an empty MBR partition table.

## Members

### `Signature`

Specifies the disk signature value, which uniquely identifies the disk.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk)