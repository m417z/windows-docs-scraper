# _USB_PROTOCOLS structure

## Description

The **USB_PROTOCOLS** union is used to report the Universal Serial Bus (USB) signaling protocols that are supported by the port.

The supported protocols are retrieved in the [USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2) structure by the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) I/O control request.

In the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) request, the caller specifies a bitwise **OR** of one or more flags defined in **USB_PROTOCOLS**. Upon successful completion, the request retrieves flags, which indicate the protocols that are actually supported by the port.

## Members

### `ul`

A bitmask that indicates the USB signaling protocols that are supported by the port.

### `Usb110`

If **TRUE**, the port supports the protocols that are defined in the USB 1.1 Specification. This indicates that the port supports full-speed and low-speed operations. **Usb110** is always TRUE for high-speed ports because those ports support full-speed and low-speed operations through split transactions and transaction translators.

### `Usb200`

If **TRUE**, the port supports the protocols that are defined USB 2.0 Specification. This indicates that the port supports high-speed operations.

### `Usb300`

If **TRUE**, the port supports the protocols that are defined USB 3.0 Specification. This indicates that the port supports SuperSpeed operations.

### `ReservedMBZ`

Reserved. Do not use.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2)

[USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2)