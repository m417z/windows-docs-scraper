# _USBFN_INTERFACE_ATTACH structure

## Description

Stores pointers to driver-implemented callback functions for handling attach and detach operations.

## Members

### `InterfaceHeader`

The interface version number.

### `GetAttachAction`

A pointer to the driver's implementation of the [USBFN_GET_ATTACH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_get_attach_action) callback function.

### `GetAttachActionAbortOperation`

A pointer to the driver's implementation of the [USBFN_GET_ATTACH_ACTION_ABORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_get_attach_action_abort) callback function.

### `SetDeviceState`

A pointer to the driver's implementation of the [USBFN_SET_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/nc-usbfnattach-usbfn_set_device_state) callback function.

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))