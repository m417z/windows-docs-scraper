# USB_DRIVER_VERSION_PARAMETERS structure

## Description

The **USB_DRIVER_VERSION_PARAMETERS** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve version information.

## Members

### `DriverTrackingCode`

A tracking code that identifies the revision of the USB stack.

### `USBDI_Version`

The version of the USB driver interface that the USB stack supports.

### `USBUSER_Version`

The version of the USB user interface that the USB stack supports.

### `CheckedPortDriver`

A Boolean value that indicates whether the checked version of the host controller driver is loaded. If **TRUE**, the checked version of the host controller driver is loaded. If **FALSE**, the checked version is not loaded.

### `CheckedMiniportDriver`

A Boolean value that indicates whether the checked version of the host controller miniport driver is loaded. If **TRUE**, the checked version of the host controller miniport driver is loaded. If **FALSE**, the checked version is not loaded.

### `USB_Version`

The USB version that the USB stack supports. A value of 0x0110 indicates that the USB stack supports version 1.1. A value of 0x0200 indicates the USB stack supports version 2.0.

## Remarks

The **USB_DRIVER_VERSION_PARAMETERS** structure is used with the USBUSER_GET_USB_DRIVER_VERSION user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)