# IOCTL_INTERNAL_USB_GET_BUS_INFO IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_BUS_INFO** I/O request queries the bus driver for certain bus information.

**IOCTL_INTERNAL_USB_GET_BUS_INFO** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** should be a pointer to a [**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification) structure.

### Input buffer length

The size of a [**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification) structure.

### Output buffer

**Parameters.Others.Argument1** points to a [**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification) structure that has the **TotalBandwidth**, **ConsumedBandwidth**, and **ControllerNameLength** fields filled in.

### Output buffer length

The size of a [**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## See also

[**USB_BUS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_bus_notification)