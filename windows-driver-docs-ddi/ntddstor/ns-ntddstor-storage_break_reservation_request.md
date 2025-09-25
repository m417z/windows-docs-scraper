# STORAGE_BREAK_RESERVATION_REQUEST structure

## Description

The STORAGE_BREAK_RESERVATION_REQUEST structure is used in conjunction with the [IOCTL_STORAGE_BREAK_RESERVATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_break_reservation) request to free a disk resource that was previously reserved.

## Members

### `Length`

Contains the length of this structure in bytes.

### `_unused`

Reserved. Do not use.

### `PathId`

Indicates the number of the bus to be reset.

### `TargetId`

Contains the number of the target device.

### `Lun`

Contains the logical unit number.

## See also

[IOCTL_STORAGE_BREAK_RESERVATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_break_reservation)