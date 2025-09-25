# _WDF_USB_BMREQUEST_TYPE enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_BMREQUEST_TYPE** enumeration identifies the data transfer type for a USB control transfer.

## Constants

### `BmRequestStandard:0`

The data transfer is a standard USB control transfer.

### `BmRequestClass`

The data transfer is a device class-specific USB control transfer.

### `BmRequestVendor`

The data transfer is a vendor-specific USB control transfer.

## Remarks

The **WDF_USB_BMREQUEST_TYPE** enumeration is used in the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

For more information about data transfer types for a USB control transfer, see the USB specification.

## See also

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)