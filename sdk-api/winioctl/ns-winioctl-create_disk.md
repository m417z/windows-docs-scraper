# CREATE_DISK structure

## Description

Contains information that the
[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk) control code uses to initialize GUID partition table (GPT), master boot record (MBR), or raw disks.

## Members

### `PartitionStyle`

The format of a partition.

For more information, see
[PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-partition_style).

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

A
[CREATE_DISK_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_mbr) structure that contains disk information when an MBR disk is to be initialized.

### `DUMMYUNIONNAME.Gpt`

A
[CREATE_DISK_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_gpt) structure that contains disk information when a GPT disk is to be initialized.

## See also

[CREATE_DISK_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_gpt)

[CREATE_DISK_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_mbr)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk)

[PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-partition_style)