# IOCTL_INTERNAL_USB_SUBMIT_URB IOCTL

## Description

The **IOCTL_INTERNAL_USB_SUBMIT_URB** I/O control request is used by drivers to submit an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to the bus driver.

**IOCTL_INTERNAL_USB_SUBMIT_URB** is a kernel-mode I/O control request. This request targets the USB hub PDO.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** points to the URB, a variable-length structure. The **UrbHeader.Function** member of the URB specifies the URB type. The length of URB, as well as the meaning of any additional members depends on the value of **UrbHeader.Function**. See [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for details.

### Input buffer length

The **UrbHeader.Length** member specifies the size in bytes of the URB.

### Output buffer

**Parameters.Others.Argument1** points to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure. The **UrbHeader.Status** contains a USB status code for the requested operation. Any additional output depends on the **UrbHeader.Function** member of the URB submitted. See **URB** for details.

### Output buffer length

The **UrbHeader.Length** member specifies the size in bytes of the URB.

### Input/output buffer

### Input/output buffer length

### Status block

The lower-level drivers will set **Irp->IoStatus.Status** to STATUS_SUCCESS if the URB can be successfully processed. Otherwise, the bus driver will set it to the appropriate error condition, such as STATUS_INVALID_PARAMETER, or STATUS_INSUFFICIENT_RESOURCES.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)