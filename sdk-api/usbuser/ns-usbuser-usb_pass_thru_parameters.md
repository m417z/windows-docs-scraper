# USB_PASS_THRU_PARAMETERS structure

## Description

The **USB_PASS_THRU_PARAMETERS** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to pass a vendor-specific command to the host controller miniport driver.

## Members

### `FunctionGUID`

A GUID that identifies the operation for the host controller miniport driver.

### `ParameterLength`

The size, in bytes, of the USB_PASS_THRU_PARAMETERS structure.

### `Parameters`

A variable length array with the parameter data for the command.

## Remarks

The **USB_PASS_THRU_PARAMETERS** structure is used with the [USBUSER_PASS_THRU](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_pass_thru_request) user-mode request. For more information about this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)