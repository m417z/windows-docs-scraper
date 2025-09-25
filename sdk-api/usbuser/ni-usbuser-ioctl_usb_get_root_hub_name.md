# IOCTL_USB_GET_ROOT_HUB_NAME IOCTL

## Description

The **IOCTL_USB_GET_ROOT_HUB_NAME** I/O control request is used with the [USB_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_root_hub_name) structure to retrieve the symbolic link name of the root hub.

**IOCTL_USB_GET_ROOT_HUB_NAME** is a user-mode I/O control request. This request targets the USB host controller (GUID_DEVINTERFACE_USB_HOST_CONTROLLER).

## Parameters

### Input buffer

None.

### Input buffer length

None.

### Output buffer

On output, the **AssociatedIrp.SystemBuffer** member points to a [USB_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_root_hub_name) structure that contains the symbolic link name of the root hub. The leading "\xxx\ " text is not included in the retrieved string.

### Output buffer length

The size of a [USB_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_root_hub_name) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

If the root hub is removed or stopped, the request returns STATUS_SUCCESS but the string is NULL.

## See also

[USB_ROOT_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_root_hub_name)