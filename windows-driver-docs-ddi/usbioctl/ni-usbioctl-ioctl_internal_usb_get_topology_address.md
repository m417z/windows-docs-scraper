# IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS**
I/O request returns information about the host controller the USB device is attached to, and the device's location in the USB device tree.

**IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of DISPATCH_LEVEL or lower.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** points to a [USB_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_topology_address) structure to receive the device topology information.

### Input buffer length

The size of a [USB_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_topology_address) structure.

### Output buffer

**Parameters.Others.Argument1** points to a [USB_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_topology_address) structure containing the device topology information.

### Output buffer length

The size of a [USB_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_topology_address) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The hub or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## See also

**USB_TOPOLOGY_ADDRESS**