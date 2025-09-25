# _URB_CONTROL_DESCRIPTOR_REQUEST structure

## Description

The **_URB_CONTROL_DESCRIPTOR_REQUEST** structure is used by USB client drivers to get or set descriptors on a USB device.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be one of the following:

**Hdr.Length** must equal `sizeof(_URB_CONTROL_DESCRIPTOR_REQUEST)`.

### `Reserved`

Reserved. Do not use.

### `Reserved0`

Reserved. Do not use.

### `TransferBufferLength`

Specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**. The host controller driver returns the number of bytes sent to or read from the pipe in this member.

### `TransferBuffer`

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in **TransferBufferMDL**.

### `TransferBufferMDL`

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in **TransferBuffer**. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

### `Reserved1`

Reserved. Do not use.

### `Index`

Specifies the device-defined index of the descriptor that is being retrieved or set.

### `DescriptorType`

Indicates what type of descriptor is being retrieved or set. One of the following values must be specified:

| usbspec.h constant | Value | USB Version |
|-------------------------------------------------------------------|:-----:|:------------------:|
| USB\_DEVICE\_DESCRIPTOR\_TYPE | 0x01 | USB 1.1 |
| USB\_CONFIGURATION\_DESCRIPTOR\_TYPE | 0x02 | USB 1.1 |
| USB\_STRING\_DESCRIPTOR\_TYPE | 0x03 | USB 1.1 |
| USB\_INTERFACE\_DESCRIPTOR\_TYPE | 0x04 | USB 1.1 |
| USB\_ENDPOINT\_DESCRIPTOR\_TYPE | 0x05 | USB 1.1 |
| USB\_DEVICE\_QUALIFIER\_DESCRIPTOR\_TYPE | 0x06 | USB 2.0 |
| USB\_OTHER\_SPEED\_CONFIGURATION\_DESCRIPTOR\_TYPE | 0x07 | USB 2.0 |
| USB\_INTERFACE\_POWER\_DESCRIPTOR\_TYPE | 0x08 | USB 2.0 |
| USB\_OTG\_DESCRIPTOR\_TYPE | 0x09 | USB 3.0 |
| USB\_DEBUG\_DESCRIPTOR\_TYPE | 0x0a | USB 3.0 |
| USB\_INTERFACE\_ASSOCIATION\_DESCRIPTOR\_TYPE | 0x0b | USB 3.0 |
| USB\_BOS\_DESCRIPTOR\_TYPE | 0x0f | USB 3.0 |
| USB\_DEVICE\_CAPABILITY\_DESCRIPTOR\_TYPE | 0x10 | USB 3.0 |
| USB\_SUPERSPEED\_ENDPOINT\_COMPANION\_DESCRIPTOR\_TYPE | 0x30 | USB 3.0 |
| USB\_20\_HUB\_DESCRIPTOR\_TYPE | 0x29 | USB 1.1<br>USB 2.0 |
| USB\_30\_HUB\_DESCRIPTOR\_TYPE | 0x2a | USB 3.0 |
| USB\_SUPERSPEEDPLUS\_ISOCH\_ENDPOINT\_COMPANION\_DESCRIPTOR\_TYPE | 0x31 | USB 3.1 |

### `LanguageId`

Specifies the language ID of the descriptor to be retrieved when USB_STRING_DESCRIPTOR_TYPE is set in **DescriptorType**. This member must be set to zero for any other value in **DescriptorType**.

### `Reserved2`

Reserved. Do not use.

## Remarks

Drivers can use the **UsbBuildGetDescriptorRequest** service routine to format this URB. If the caller passes a buffer too small to hold all of the data, the bus driver truncates the data to fit in the buffer without error.

When the caller requests the device descriptor, the bus driver returns a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) data structure.

When the caller requests a configuration descriptor, the bus driver returns the configuration descriptor in a [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure, followed by the interface and endpoint descriptors for that configuration. The driver can access the interface and endpoint descriptors as [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) and [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structures. The bus driver also returns any class-specific or device-specific descriptors. The system provides the [USBD_ParseConfigurationDescriptorEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parseconfigurationdescriptorex) and [USBD_ParseDescriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parsedescriptors) service routines to find individual descriptors within the buffer.

When the caller requests a string descriptor, the bus driver returns a [USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor) structure. The string itself is found in the variable-length **bString** member of the string descriptor.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)