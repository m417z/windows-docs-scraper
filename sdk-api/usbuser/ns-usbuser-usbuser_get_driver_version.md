# USBUSER_GET_DRIVER_VERSION structure

## Description

The **USBUSER_GET_DRIVER_VERSION** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to read driver and interface version information.

## Members

### `Header`

A [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) structure that specifies the user-mode request on input to [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) and provides buffer and status information on output.

### `Parameters`

A [USB_DRIVER_VERSION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_driver_version_parameters) structure that specifies the parameters that are associated with this request.

## Remarks

The **USBUSER_GET_DRIVER_VERSION** structure is used with the USBUSER_GET_USB_DRIVER_VERSION user-mode request. For more information about this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header)

[USB_DRIVER_VERSION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_driver_version_parameters)