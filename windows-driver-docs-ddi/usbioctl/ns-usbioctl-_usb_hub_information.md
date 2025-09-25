# _USB_HUB_INFORMATION structure

## Description

The **USB_HUB_INFORMATION** structure contains information about a hub.

## Members

### `HubDescriptor`

A [USB_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_hub_descriptor) structure that contains selected information from the hub descriptor.

### `HubIsBusPowered`

A Boolean value that indicates whether the hub is bus-powered. **TRUE**, the hub is bus-powered; **FALSE**, the hub is self-powered.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_hub_descriptor)

[USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information)