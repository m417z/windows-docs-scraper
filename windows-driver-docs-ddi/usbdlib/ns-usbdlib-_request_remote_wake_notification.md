# _REQUEST_REMOTE_WAKE_NOTIFICATION structure

## Description

The purpose of the **REQUEST_REMOTE_WAKE_NOTIFICATION** structure is to specify input parameters for the [IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_request_remote_wake_notification) I/O control request.

## Members

### `Version`

The version of this structure. Set to 0.

### `Size`

The size of the **REQUEST_REMOTE_WAKE_NOTIFICATION** structure.

### `UsbdFunctionHandle`

A function handle that is associated with the function that sends the resume signal. The handle was obtained in a previous [IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device) request.

### `Interface`

Specifies the device-defined index identifier of the interface with which the function is associated.

## See also

[How to Implement Function Suspend in a Composite Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device)

[IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_request_remote_wake_notification)