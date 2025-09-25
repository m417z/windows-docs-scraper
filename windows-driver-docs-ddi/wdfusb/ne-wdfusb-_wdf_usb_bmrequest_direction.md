# _WDF_USB_BMREQUEST_DIRECTION enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_BMREQUEST_DIRECTION** enumeration identifies the data transfer direction for a USB control transfer.

## Constants

### `BmRequestHostToDevice:0`

The data transfer direction is from the host system to the device.

### `BmRequestDeviceToHost`

The data transfer direction is from the device to the host system.

## Remarks

The **WDF_USB_BMREQUEST_DIRECTION** enumeration is used in the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

For more information about the data transfer direction for a USB control transfer, see the USB specification.

## See also

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)