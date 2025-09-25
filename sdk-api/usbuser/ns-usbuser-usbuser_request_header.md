# USBUSER_REQUEST_HEADER structure

## Description

The **USBUSER_REQUEST_HEADER** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to send a user-mode request to the USB host controller driver.

## Members

### `UsbUserRequest`

The user-mode request. For a list and description of possible values for this member, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

### `UsbUserStatusCode`

The status code that is returned by port driver.

### `RequestBufferLength`

The size, in bytes, of the data buffer. The same buffer is used for both input and output.

### `ActualBufferLength`

The size, in bytes, of the data that is retrieved by the request.

## Remarks

The **USBUSER_REQUEST_HEADER** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to send a user-mode request to the USB port driver.

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)