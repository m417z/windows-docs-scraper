# _CONNECT_DATA structure

## Description

CONNECT_DATA specifies information that Kbdclass and Mouclass use to connect to a keyboard or mouse port.

## Members

### `ClassDeviceObject`

Pointer to an upper-level class [filter device object](https://learn.microsoft.com/windows-hardware/drivers/) (filter DO).

### `ClassService`

Specifies the class service routine. See [PSERVICE_CALLBACK_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/nc-kbdmou-pservice_callback_routine).

## Remarks

The keyboard class driver uses this structure with an [IOCTL_INTERNAL_KEYBOARD_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_keyboard_connect) request; the mouse class driver uses [IOCTL_INTERNAL_MOUSE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_mouse_connect) .