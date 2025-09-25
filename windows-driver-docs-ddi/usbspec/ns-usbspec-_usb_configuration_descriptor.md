# _USB_CONFIGURATION_DESCRIPTOR structure

## Description

The **USB_CONFIGURATION_DESCRIPTOR** structure is used by USB client drivers to hold a USB-defined configuration descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.3.

## Members

### `bLength`

Specifies the length, in bytes, of this structure.

### `bDescriptorType`

Specifies the descriptor type. Must be set to USB_CONFIGURATION_DESCRIPTOR_TYPE.

### `wTotalLength`

Specifies the total length, in bytes, of all data for the configuration. The length includes all interface, endpoint, class, or vendor-specific descriptors that are returned with the configuration descriptor.

### `bNumInterfaces`

Specifies the total number of interfaces supported by this configuration.

### `bConfigurationValue`

Contains the value that is used to select a configuration. This value is passed to the USB SetConfiguration request , as described in version 1.1 of the Universal Serial Bus Specification. The port driver does not currently expose a service that allows higher-level drivers to set the configuration.

### `iConfiguration`

Specifies the device-defined index of the string descriptor for this configuration.

### `bmAttributes`

Specifies a bitmap to describe behavior of this configuration. The bits are described and set in little-endian order.

| Bit | Meaning |
| --- | --- |
| 0 - 4 | Reserved. |
| 5 | The configuration supports remote wakeup. |
| 6 | The configuration is self-powered and does not use power from the bus. |
| 7 | The configuration is powered by the bus. |

### `MaxPower`

Specifies the power requirements of this device in two-milliampere units. This member is valid only if bit seven is set in **bmAttributes**.

## Remarks

If **wTotalLength** is greater than the buffer size provided in the URB to hold all descriptors retrieved (interface, endpoint, class, and vendor-defined), incomplete data will be returned. In order to retrieve complete descriptors, the request will need to be re-sent with a larger buffer.

If **bmAttributes** bits six and seven are both set, then the device is powered both by the bus and by a source external to the bus.

Other members that are part of this structure but not described here should be treated as opaque and considered to be reserved for system use.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_CreateConfigurationRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequest)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))