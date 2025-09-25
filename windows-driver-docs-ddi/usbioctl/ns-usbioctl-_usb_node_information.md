# _USB_NODE_INFORMATION structure

## Description

The **USB_NODE_INFORMATION** structure is used with the [IOCTL_USB_GET_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_information) I/O control request to retrieve information about a parent device.

## Members

### `NodeType`

A [USB_HUB_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_hub_node) enumerator that indicates whether the parent device is a hub or a non-hub composite device.

### `u`

The members of the **u** union are as follows:

### `u.HubInformation`

A [USB_HUB_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information) structure that contains information about a parent hub device.

### `u.MiParentInformation`

A [USB_MI_PARENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_mi_parent_information) structure that contains information about a parent non-hub, composite device.

## Remarks

A parent device can be either a hub or a composite device. The USB stack treats the interfaces of a composite device as though they were children of the composite device. The **USB_NODE_INFORMATION** structure can hold information about either kind of parent device (both hubs and composite devices).

## See also

[IOCTL_USB_GET_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_information)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information)

[USB_HUB_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_hub_node)

[USB_MI_PARENT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_mi_parent_information)