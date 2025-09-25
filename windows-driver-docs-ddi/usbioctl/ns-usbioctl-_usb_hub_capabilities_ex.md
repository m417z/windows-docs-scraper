# _USB_HUB_CAPABILITIES_EX structure

## Description

The **USB_HUB_CAPABILITIES_EX** structure is used with the [IOCTL_USB_GET_HUB_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_capabilities) I/O control request to retrieve the capabilities of a particular USB hub.

## Members

### `CapabilityFlags`

A [USB_HUB_CAP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_cap_flags) structure that reports the hub capabilities.

## See also

[IOCTL_USB_GET_HUB_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_capabilities)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_CAP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_cap_flags)