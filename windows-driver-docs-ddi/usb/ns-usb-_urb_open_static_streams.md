# _URB_OPEN_STATIC_STREAMS structure

## Description

The **_URB_OPEN_STATIC_STREAMS** structure is used by a USB client driver to open streams in the specified bulk endpoint.

To format the URB, call the [UsbBuildOpenStaticStreamsRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbbuildopenstaticstreamsrequest) function.

## Members

### `Hdr`

The [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_OPEN_STATIC_STREAMS, and **Hdr.Length** must be `sizeof(_URB_OPEN_STATIC_STREAMS)`.

### `PipeHandle`

An opaque handle for the pipe associated with the endpoint that supports the streams to open.

The client driver obtains **PipeHandle** from the URB_FUNCTION_SELECT_CONFIGURATION or URB_FUNCTION_SELECT_INTERFACE request.

### `NumberOfStreams`

The number of streams to open. The **NumberOfStreams** value indicates the number of elements in the array pointed to by **Streams**. This value must be greater than zero and less than or equal to the maximum number of streams supported by the USB driver stack, the host controller, and the endpoint in the device. For more information, see Remarks.

### `StreamInfoVersion`

Version of the [USBD_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_stream_information) structure. Must be set to URB_OPEN_STATIC_STREAMS_VERSION_100; otherwise, the request fails and the URB status is USBD_STATUS_INVALID_PARAMETER.

### `StreamInfoSize`

Size of the [USBD_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_stream_information) structure. **StreamInfoSize** must be `sizeof(USBD_STREAM_INFORMATION)`;
otherwise, the request fails and the URB status is USBD_STATUS_INFO_LENGTH_MISMATCH.

### `Streams`

Pointer to a caller-allocated, initialized array of [USBD_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_stream_information) structures. The length of the array depends on the number of streams to open and must be the same as the **NumberOfStreams** value. For more information, see Remarks.

## Remarks

To use streams (other than the default stream) in the endpoint for I/O operations, the client driver opens the required streams by sending an open-stream request (URB_FUNCTION_OPEN_STATIC_STREAMS) to the USB driver stack. For the request, the client driver must format the URB by initializing the **_URB_OPEN_STATIC_STREAMS** structure. To format the URB, call the [UsbBuildOpenStaticStreamsRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbbuildopenstaticstreamsrequest) function.

The maximum number of streams that can be opened by a client driver, must be less than or equal to the maximum number of streams supported by the USB driver stack, the host controller, and the bulk endpoint. To get the maximum number of streams supported by the host controller, call [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)). The USB driver stack supports up to 255 streams. If the client driver requests more than 255 streams, **USBD_QueryUsbCapability** fails the request. To get the maximum number of streams supported by the endpoint, inspect the endpoint companion descriptor (see [USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_superspeed_endpoint_companion_descriptor) in Usbspec.h).

For information about formatting the URB for the open-stream request and code example, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

When the client driver is finished using the streams, the driver can close all streams associated with a particular endpoint by sending a close-stream request. To send the request, the client driver must specify information about the endpoint in the [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request) structure. The **Hdr** member of **_URB_PIPE_REQUEST** must be URB_FUNCTION_CLOSE_STATIC_STREAMS; the **PipeHandle** member must be the handle to the endpoint that contains the streams in use.

## See also

[How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)