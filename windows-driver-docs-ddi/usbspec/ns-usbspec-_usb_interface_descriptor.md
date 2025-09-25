# _USB_INTERFACE_DESCRIPTOR structure

## Description

The **USB_INTERFACE_DESCRIPTOR** structure is used by USB client drivers to retrieve a USB-defined interface descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.5.

## Members

### `bLength`

The length, in bytes, of the descriptor.

### `bDescriptorType`

The descriptor type. **bDescriptor** must be set to USB_INTERFACE_DESCRIPTOR_TYPE.

### `bInterfaceNumber`

The index number of the interface.

### `bAlternateSetting`

The index number of the alternate setting of the interface.

### `bNumEndpoints`

The number of endpoints that are used by the interface, excluding the default status endpoint.

### `bInterfaceClass`

The class code of the device that the USB specification group assigned.

### `bInterfaceSubClass`

The subclass code of the device that the USB specification group assigned.

### `bInterfaceProtocol`

The protocol code of the device that the USB specification group assigned.

### `iInterface`

The index of a string descriptor that describes the interface. For information about this field, see section 9.6.5 in the "Universal Serial Bus Revision 2.0" specification at [USB Technology](https://www.usb.org/documents).

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)