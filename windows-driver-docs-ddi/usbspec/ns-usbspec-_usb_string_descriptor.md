# _USB_STRING_DESCRIPTOR structure

## Description

The **USB_STRING_DESCRIPTOR** structure is used by USB client drivers to hold a USB-defined string descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.9.

## Members

### `bLength`

Specifies the length, in bytes, of the descriptor.

### `bDescriptorType`

Specifies the descriptor type. Must always be USB_STRING_DESCRIPTOR_TYPE.

### `bString`

Pointer to a client-allocated buffer that contains, on return from the host controller driver, a Unicode string with the requested string descriptor.

## Remarks

This structure is used to hold a device, configuration, interface, class, vendor, endpoint, or device string descriptor. The string descriptor provides a human-readable description of the component.

Strings returned in **bString** are in Unicode format and the contents of the strings are device-defined.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)