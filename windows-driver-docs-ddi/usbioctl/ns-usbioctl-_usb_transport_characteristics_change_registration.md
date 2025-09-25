# _USB_TRANSPORT_CHARACTERISTICS_CHANGE_REGISTRATION structure

## Description

Contains registration information for the [IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change) request.

## Members

### `ChangeNotificationInputFlags`

A bitmask set by the client driver to register for change notifications that it is interested in. The following bits are valid:

| Value | Meaning |
| ----- | ------- |
| USB_REGISTER_FOR_TRANSPORT_LATENCY_CHANGE (0x1) | The client is notified of changes in transport latency. |
| USB_REGISTER_FOR_TRANSPORT_BANDWIDTH_CHANGE (0x2) | The client is notified of changes in bandwidth. |

### `Handle`

An opaque handle for this registration.

### `UsbTransportCharacteristics`

A [USB_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics) structure that is filled by the USB driver stack with the initial values of the transport characteristics.

## Remarks

The registration handle received in this request is valid until the caller sends the [IOCTL_USB_UNREGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_unregister_for_transport_characteristics_change) request to unregister for notifications.

## See also

[IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change)