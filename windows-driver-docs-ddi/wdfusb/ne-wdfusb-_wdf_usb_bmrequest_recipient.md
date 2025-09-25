# _WDF_USB_BMREQUEST_RECIPIENT enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_BMREQUEST_RECIPIENT** enumeration identifies the data transfer recipient for a USB control transfer.

## Constants

### `BmRequestToDevice:0`

The data transfer recipient is a device.

### `BmRequestToInterface`

The data transfer recipient is a device interface.

### `BmRequestToEndpoint`

The data transfer recipient is a pipe endpoint.

### `BmRequestToOther`

The data transfer recipient is not a device, interface, or endpoint.

## Remarks

The**WDF_USB_BMREQUEST_RECIPIENT** enumeration is used in the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

For more information about the data transfer recipient for a USB control transfer, see the USB specification.

## See also

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)