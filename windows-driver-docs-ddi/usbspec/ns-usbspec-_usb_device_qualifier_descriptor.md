# _USB_DEVICE_QUALIFIER_DESCRIPTOR structure

## Description

The **USB_DEVICE_QUALIFIER_DESCRIPTOR** structure is used by USB client drivers to retrieve a USB-defined device qualifier descriptor.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorType`

Specifies the descriptor type. Must be set to **USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE**.

### `bcdUSB`

Identifies the version of the USB specification that this descriptor structure complies with. This value is a binary-coded decimal number.

### `bDeviceClass`

Specifies the class code of the device as assigned by the USB specification group.

### `bDeviceSubClass`

Specifies the subclass code of the device as assigned by the USB specification group.

### `bDeviceProtocol`

Specifies the protocol code of the device as assigned by the USB specification group.

### `bMaxPacketSize0`

Specifies the maximum packet size, in bytes, for endpoint zero of the device. The value must be set to 8, 16, 32, or 64.

### `bNumConfigurations`

Specifies the total number of possible configurations for the device.

### `bReserved`

Reserved.

## Remarks

This structure is similar to [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), but it contains only those members that can change when the device switches from full-speed operation to high-speed operation or vice versa. If the device is operating at full speed, querying for this descriptor will contain information about how the device would operate at high-speed. If, on the other hand, the device is operating at high-speed, this descriptor will contain information about how the device would operate at full-speed.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)