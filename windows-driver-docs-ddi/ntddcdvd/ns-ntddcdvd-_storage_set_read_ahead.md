# _STORAGE_SET_READ_AHEAD structure

## Description

The STORAGE_SET_READ_AHEAD structure is used in conjunction with the [IOCTL_STORAGE_SET_READ_AHEAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_storage_set_read_ahead) request to instruct the device to skip to the target address upon reaching the trigger address.

## Members

### `TriggerAddress`

Indicates the address at which the device jumps to the target address.

### `TargetAddress`

Indicates the address to jump to.

## See also

[IOCTL_STORAGE_SET_READ_AHEAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_storage_set_read_ahead)