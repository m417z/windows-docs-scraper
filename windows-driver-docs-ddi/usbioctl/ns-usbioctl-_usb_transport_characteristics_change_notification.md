# _USB_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION structure

## Description

Contains registration information filled when the [IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change)

request completes.

## Members

### `Handle`

An opaque handle for this registration.

### `UsbTransportCharacteristics`

A [USB_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics) structure that is filled by the USB driver stack with the initial values of the transport characteristics.

## See also

[IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change)