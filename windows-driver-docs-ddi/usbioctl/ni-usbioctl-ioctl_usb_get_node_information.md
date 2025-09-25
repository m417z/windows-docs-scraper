# IOCTL_USB_GET_NODE_INFORMATION IOCTL

## Description

The **IOCTL_USB_GET_NODE_INFORMATION** I/O control request is used with the [USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information) structure to retrieve information about a parent device.

**IOCTL_USB_GET_NODE_INFORMATION** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

On input, the **AssociatedIrp.SystemBuffer** member points to a [USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information) structure. On input, the **NodeType** member of this structure must indicate whether the parent device is a hub or a non-hub composite device.

### Input buffer length

The size of a [USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information) structure.

### Output buffer

On output, **AssociatedIrp.SystemBuffer** points to a [USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information) structure that holds information about the parent device.

### Output buffer length

The size of a [USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information)