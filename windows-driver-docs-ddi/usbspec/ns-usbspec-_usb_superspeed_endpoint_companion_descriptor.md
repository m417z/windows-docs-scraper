# _USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR structure

## Description

The **USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR** structure is used by USB client drivers to retrieve a USB-defined SuperSpeed Endpoint Companion descriptor.

The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 9.6.7.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorType`

Specifies the descriptor type. Must be set to USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR.

### `bMaxBurst`

Specifies the maximum number of packets that the endpoint can send or receive as a part of a burst.

### `bmAttributes`

### `bmAttributes.AsUchar`

Specifies the length of the structures.

### `bmAttributes.Bulk`

### `bmAttributes.Bulk.MaxStreams`

Specifies the maximum number of streams supported by the bulk endpoint.

### `bmAttributes.Bulk.Reserved1`

Reserved. Do not use.

### `bmAttributes.Isochronous`

### `bmAttributes.Isochronous.Mult`

Specifies a zero-based number that determines the maximum number of packets (bMaxBurst * (Mult + 1)) that can be sent to the endpoint within a service interval.

### `bmAttributes.Isochronous.Reserved2`

Reserved. Do not use.

### `bmAttributes.Isochronous.SspCompanion`

### `wBytesPerInterval`

Number of bytes per interval.

## Remarks

A client driver that supports streams associated with a bulk endpoint, uses **USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR** to get the maximum number of streams supported by the endpoint. That information is required by the client driver in an open-streams request. In the request, the specified value for **NumberOfStreams** member of the [_URB_OPEN_STATIC_STREAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_open_static_streams) structure cannot exceed the **MaxStreams** value reported in **USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR**. For more information about opening streams, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)