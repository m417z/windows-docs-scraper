# CREATE_DISK_GPT structure

## Description

Contains information used by the
[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk) control code to initialize GUID partition table (GPT) disks.

## Members

### `DiskId`

The disk identifier (GUID) of the GPT disk to be initialized.

### `MaxPartitionCount`

The maximum number of partitions allowed on the GPT disk to be initialized without repartitioning the disk.

## Remarks

The
**CREATE_DISK_GPT** structure is defined as part of the
[CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk) structure.

If a maximum partition count of less than 128 is specified, it will be reset to 128. This is in compliance with the EFI specification.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk)

[CREATE_DISK_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_mbr)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk)