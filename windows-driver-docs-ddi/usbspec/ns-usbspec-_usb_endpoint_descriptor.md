# _USB_ENDPOINT_DESCRIPTOR structure

## Description

The **USB_ENDPOINT_DESCRIPTOR** structure is used by USB client drivers to retrieve a USB-defined endpoint descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.6.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorType`

Specifies the descriptor type. Must be set to USB_ENDPOINT_DESCRIPTOR_TYPE.

### `bEndpointAddress`

Specifies the USB-defined endpoint address. The four low-order bits specify the endpoint number. The high-order bit specifies the direction of data flow on this endpoint: 1 for in, 0 for out.

### `bmAttributes`

The two low-order bits specify the endpoint type, one of USB_ENDPOINT_TYPE_CONTROL, USB_ENDPOINT_TYPE_ISOCHRONOUS, USB_ENDPOINT_TYPE_BULK, or USB_ENDPOINT_TYPE_INTERRUPT.

### `wMaxPacketSize`

Specifies the maximum packet size that can be sent from or to this endpoint.

### `bInterval`

The **bInterval** value contains the polling interval for interrupt and isochronous endpoints. For other types of endpoint, this value should be ignored. This value reflects the device's configuration in firmware. Drivers cannot change it.

The polling interval, together with the speed of the device and the type of host controller, determine the frequency with which the driver should initiate an interrupt or an isochronous transfer. The value in **bInterval** does not represent a fixed amount of time. It is a relative value, and the actual polling frequency will also depend on whether the device and the USB host controller operate at low, full or high speed.

If either the host controller or the device operates at low speed, the period of time between interrupt transfers (also known as the polling "period") is measured in units of 1 millisecond frames, and the period is related to the value in **bInterval** as indicated the following table:

| Value of bInterval | Polling Period (1-millisecond frames) | Interrupt |
| --- | --- | --- |
| 0 to 15 | 8 | Supported. |
| 16 to 35 | 16 | Supported. |
| 36 to 255 | 32 | Supported. |
| > 255 | Polling intervals > 255 are forbidden by the USB specification. |  |

For devices and host controllers that can operate at full speed, the period is measured in units of 1 millisecond frames, and the period is related to the value in **bInterval** as indicated the following table:

| Value of bInterval | Polling Period (1-millisecond frames) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 1 | 1 | Supported. | Supported. |
| 2 to 3 | 2 | Supported. | Supported. |
| 4 to 7 | 4 | Supported. | Supported. |
| 8 to 15 | 8 | Supported. | Supported. |
| 16 to 31 | 16 | Supported. | Not supported. |
| 32 to 255 | 32 | Supported. | Not supported. |
| > 255 | Polling intervals > 255 are forbidden by the USB specification. |  |  |

For devices and host controllers that can operate at high speed, the period is measured in units of microframes. There are eight microframes in each 1 millisecond frame. The period is related to the value in **bInterval** by the formula Period = 2 ** (**bInterval** - 1), as indicated the following table:

| Value of bInterval | Polling Period (microframes) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 1 | 1 | Supported. | Supported. |
| 2 | 2 | Supported. | Supported. |
| 3 | 4 | Supported. | Supported. |
| 4 | 8 | Supported. | Supported. |
| 5 | 16 | Supported. | Not supported. |
| 6 | 32 | Supported. | Not supported. |
| 7 to 255 | 32 | Supported. | Not supported. |
| > 255 | Polling intervals > 255 are forbidden by the USB specification. |  |  |

The mappings in the preceding tables between periods and polling intervals are valid in Windows 2000 and later operating systems.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85))

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)