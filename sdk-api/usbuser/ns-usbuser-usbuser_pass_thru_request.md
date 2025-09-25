# USBUSER_PASS_THRU_REQUEST structure

## Description

The **USBUSER_PASS_THRU_REQUEST** structure is used in conjunction with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to send a vendor-specific command to the host controller miniport driver.

## Members

### `Header`

Contains a structure of type [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) that specifies the user-mode request on input to [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request), and provides buffer and status information on output.

### `PassThru`

Contains a structure of type [USB_PASS_THRU_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_pass_thru_parameters) that specifies the parameters associated with this request.

## Remarks

The **USBUSER_PASS_THRU_REQUEST** structure is used in conjunction with the USBUSER_PASS_THRU user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)