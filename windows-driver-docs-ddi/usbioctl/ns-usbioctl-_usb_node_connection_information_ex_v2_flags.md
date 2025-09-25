# _USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS structure

## Description

The **USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS** union is used to indicate the speed at which a USB 3.0 device is currently operating and whether it can operate at higher speed, when attached to a particular port.

Device speed information is obtained in the [USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2) structure by the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) I/O control request.

Or: the speed in which a device attached to a port is currently operating and at what speeds it is capable of operating.

## Members

### `ul`

A bitmask that indicates the USB speed of the device that is attached to the port.

### `DeviceIsOperatingAtSuperSpeedOrHigher`

If **TRUE**, the attached device is currently operating at SuperSpeed or a higher speed that is defined by the official USB specification.

### `DeviceIsSuperSpeedCapableOrHigher`

If **TRUE**, the attached device is a USB 3.0 device and is capable of operating at SuperSpeed or a higher speed that is defined by the official USB specification.

### `DeviceIsOperatingAtSuperSpeedPlusOrHigher`

### `DeviceIsSuperSpeedPlusCapableOrHigher`

### `ReservedMBZ`

Reserved. Do not use.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2)

[USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2_flags)