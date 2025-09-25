# _USB_HUB_NODE enumeration

## Description

The **USB_HUB_NODE** enumerator indicates whether a device is a hub or a composite device.

## Constants

### `UsbHub`

Indicates that the device is a hub.

### `UsbMIParent`

Indicates that the device is a composite device with multiple interfaces.

## Remarks

Composite devices are devices that have multiple interfaces. Windows loads the USB generic parent driver for composite devices, instead of the hub driver, but the generic parent driver performs many of the functions of the hub driver. It creates a child PDO for each interface, as though the interface were a separate device.

## See also

[USB Constants and Enumerations](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#enumerations)

[USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information)