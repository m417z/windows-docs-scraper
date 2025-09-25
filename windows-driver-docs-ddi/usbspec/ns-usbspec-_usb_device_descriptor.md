# _USB_DEVICE_DESCRIPTOR structure

## Description

The **USB_DEVICE_DESCRIPTOR** structure is used by USB client drivers to retrieve a USB-defined device descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.1.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorType`

Specifies the descriptor type. Must be set to **USB_DEVICE_DESCRIPTOR_TYPE**.

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

### `idVendor`

Specifies the vendor identifier for the device as assigned by the USB specification committee.

### `idProduct`

Specifies the product identifier. This value is assigned by the manufacturer and is device-specific.

### `bcdDevice`

Identifies the version of the device. This value is a binary-coded decimal number.

### `iManufacturer`

Specifies a device-defined index of the string descriptor that provides a string containing the name of the manufacturer of this device.

### `iProduct`

Specifies a device-defined index of the string descriptor that provides a string that contains a description of the device.

### `iSerialNumber`

Specifies a device-defined index of the string descriptor that provides a string that contains a manufacturer-determined serial number for the device.

### `bNumConfigurations`

Specifies the total number of possible configurations for the device.

## Remarks

This structure is used to hold a retrieved USB-defined device descriptor. This information can then be used to further configure or retrieve information about the device. Device descriptors are retrieved by submitting a get-descriptor URB.

The **iManufacturer**, **iProduct**, and **iSerialNumber** values, when returned from the host controller driver, contain index values into an array of string descriptors maintained by the device. To retrieve these strings, a string descriptor request can be sent to the device using these index values.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)