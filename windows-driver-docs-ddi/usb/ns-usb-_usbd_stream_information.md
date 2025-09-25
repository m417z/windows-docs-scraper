# _USBD_STREAM_INFORMATION structure

## Description

The **USBD_STREAM_INFORMATION** structure stores information about a stream associated with a bulk endpoint.

## Members

### `PipeHandle`

An opaque handle to the stream.

### `StreamID`

Stream identifier. The open-static streams request obtains stream identifiers that are assigned by the USB driver stack.

### `MaximumTransferSize`

Maximum transfer size (in bytes) that a client driver can send in a single URB for an I/O transfer to the stream.

### `PipeFlags`

Reserved. Do not use.

## Remarks

A client driver allocates an array of **USBD_STREAM_INFORMATION** structures and sends it in an open-streams request (URB_FUNCTION_OPEN_STATIC_STREAMS). Upon completion, the USB driver stack retrieves stream information and populates each **USBD_STREAM_INFORMATION** structure with stream information. The stream identifiers returned by the request are sequential and start at 1.

## See also

[How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)

[_URB_OPEN_STATIC_STREAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_open_static_streams)