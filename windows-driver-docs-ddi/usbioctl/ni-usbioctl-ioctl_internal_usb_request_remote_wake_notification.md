# IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION IOCTL

## Description

The **IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION**
I/O request is sent by the driver of a Universal Serial Bus (USB) multi-function device (composite driver) to request remote wake-up notifications from a specific function in the device.

**IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION** is a kernel-mode I/O control request. This request targets the USB hub physical device object (PDO).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** points to a caller-allocated and initialized [REQUEST_REMOTE_WAKE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_request_remote_wake_notification) structure that contains information about the function whose resume signal the driver is interested in. That information includes the function handle and the interface with which the function is associated.

### Input buffer length

The size of a [REQUEST_REMOTE_WAKE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_request_remote_wake_notification) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The hub or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## See also

[How to Implement Function Suspend in a Composite Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)