# _USB_HUB_INFORMATION_EX structure

## Description

The **USB_HUB_INFORMATION_EX** structure is used with the [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request to retrieve information about a Universal Serial Bus (USB) hub.

## Members

### `HubType`

The type of hub: root hub, USB 2.0, or USB 3.0 hub. On successful completion of the [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request, **HubType** contains a [USB_HUB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_hub_type) enumerator that indicates the type of hub.

### `HighestPortNumber`

Indicates the number of ports on the hub. The ports are numbered from 1 to **HighestPortNumber**, where **HighestPortNumber** is the highest valid port number on the hub.

### `u`

### `u.UsbHubDescriptor`

If **HubType** indicates a USB 2.0 hub, **u.UsbHubDescriptor** is a [USB_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_hub_descriptor) structure that contains selected information from the USB 2.0/1.1 hub descriptor, as defined in the USB 2.0 Specification.

### `u.Usb30HubDescriptor`

If **HubType** indicates a USB 3.0 hub, **u.UsbHub30Descriptor** is a [USB_30_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_30_hub_descriptor) structure that contains selected information from the USB 3.0 hub descriptor, as defined in the USB 3.0 Specification.

## See also

[IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex)

[USB_30_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_30_hub_descriptor)

[USB_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_hub_descriptor)

[USB_HUB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_hub_type)