# _DISK_CONTROLLER_NUMBER structure

## Description

DISK_CONTROLLER_NUMBER is used with IOCTL_DISK_CONTROLLER_NUMBER to retrieve the controller number and disk number of an IDE disk.

## Members

### `ControllerNumber`

Contains the number of the IDE controller for the disk.

### `DiskNumber`

Contains the number of the disk.

## Remarks

After DISK_CONTROLLER_NUMBER receives the controller number and the disk number, these values can be used to determine whether the disk is attached to the primary or to the secondary IDE controller.

## See also

[IOCTL_DISK_CONTROLLER_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_controller_number)