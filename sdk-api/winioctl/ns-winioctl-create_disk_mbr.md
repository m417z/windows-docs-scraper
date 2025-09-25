# CREATE_DISK_MBR structure

## Description

Contains information that the
[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk) control code uses to initialize master boot record (MBR) disks.

## Members

### `Signature`

The disk signature of the MBR disk to be initialized.

## Remarks

The
**CREATE_DISK_MBR** structure is part of the
[CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk) structure.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk)

[CREATE_DISK_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_disk_gpt)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_create_disk)