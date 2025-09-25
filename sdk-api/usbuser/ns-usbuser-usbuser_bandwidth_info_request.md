# USBUSER_BANDWIDTH_INFO_REQUEST structure

## Description

The **USBUSER_BANDWIDTH_INFO_REQUEST** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve information about the allocated bandwidth.

## Members

### `Header`

A [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) structure that specifies the user-mode request on input to IOCTL_USB_USER_REQUEST and provides buffer and status information on output.

### `BandwidthInformation`

A [USB_BANDWIDTH_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_bandwidth_info) structure that reports bandwidth allocation information.

## Remarks

The **USBUSER_BANDWIDTH_INFO_REQUEST** structure is used with the USBUSER_GET_BANDWIDTH_INFORMATION user-mode request. For more information about this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header)

[USB_BANDWIDTH_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_bandwidth_info)