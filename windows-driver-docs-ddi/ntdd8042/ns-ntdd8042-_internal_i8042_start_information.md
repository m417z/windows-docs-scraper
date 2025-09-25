# _INTERNAL_I8042_START_INFORMATION structure

## Description

INTERNAL_I8042_START_INFORMATION specifies the [interrupt object](https://learn.microsoft.com/windows-hardware/drivers/) that an optional, vendor-supplied, upper-level filter device driver can use to synchronize its operation with an I8042prt ISR.

## Members

### `Size`

Specifies the size, in bytes, of an INTERNAL_I8042_START_INFORMATION structure.

### `InterruptObject`

Pointer to an interrupt object. I8042prt supplies the interrupt object.

### `Reserved`

Reserved for future use.

## Remarks

This structure is used with [IOCTL_INTERNAL_I8042_KEYBOARD_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_keyboard_start_information) and [IOCTL_INTERNAL_I8042_MOUSE_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_mouse_start_information) requests.

## See also

[IOCTL_INTERNAL_I8042_KEYBOARD_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_keyboard_start_information)

[IOCTL_INTERNAL_I8042_MOUSE_START_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_mouse_start_information)