# _USB_PORT_PROPERTIES structure

## Description

The **USB_PORT_PROPERTIES** union is used to report the capabilities of a Universal Serial Bus (USB) port.

The port capabilities are retrieved in the [USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties) structure by the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) I/O control request.

## Members

### `ul`

A bitmask that indicates the properties and capabilities of the port.

### `PortIsUserConnectable`

If **TRUE**, the port is visible to the user and a USB device can be attached to or detached from the port.

### `PortIsDebugCapable`

If **TRUE**, the port supports debugging over a USB connection.

### `PortHasMultipleCompanions`

### `PortConnectorIsTypeC`

### `ReservedMBZ`

Reserved. Do not use.

## See also

[IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties)

[USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties)