# USBUSER_CONTROLLER_UNICODE_NAME structure

## Description

The **USBUSER_CONTROLLER_UNICODE_NAME** structure is used in conjunction with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve the USB host controller driverkey name.

## Members

### `Header`

Contains a structure of type [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) that specifies the user-mode request on input to [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request), and provides buffer and status information on output.

### `UnicodeName`

Contains a Unicode string of type [USB_UNICODE_NAME](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_unicode_name) that reports the host controller's driverkey name.

## Remarks

The **USBUSER_CONTROLLER_UNICODE_NAME** structure is used in conjunction with the USBUSER_GET_CONTROLLER_DRIVER_KEY user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header)

[USB_UNICODE_NAME](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_unicode_name)