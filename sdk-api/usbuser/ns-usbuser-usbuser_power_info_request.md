# USBUSER_POWER_INFO_REQUEST structure

## Description

The **USBUSER_POWER_INFO_REQUEST** structure is used in conjunction with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve power policy information concerning the relationship of a specific system state to the power state of the host controller and the root hub.

## Members

### `Header`

Contains a structure of type [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) that specifies the user-mode request on input to [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request), and provides buffer and status information on output.

### `PowerInformation`

Contains a structure of type [USB_POWER_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_power_info) that specifies the parameters associated with this request.

## Remarks

The **USBUSER_POWER_INFO_REQUEST** structure is used in conjunction with the USBUSER_GET_POWER_STATE_MAP user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)